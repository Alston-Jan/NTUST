/************************************************************************
     File:        TrainView.cpp

     Author:     
                  Michael Gleicher, gleicher@cs.wisc.edu

     Modifier
                  Yu-Chi Lai, yu-chi@cs.wisc.edu
     
     Comment:     
						The TrainView is the window that actually shows the 
						train. Its a
						GL display canvas (Fl_Gl_Window).  It is held within 
						a TrainWindow
						that is the outer window with all the widgets. 
						The TrainView needs 
						to be aware of the window - since it might need to 
						check the widgets to see how to draw

	  Note:        we need to have pointers to this, but maybe not know 
						about it (beware circular references)

     Platform:    Visio Studio.Net 2003/2005

*************************************************************************/

#include <iostream>
#include <Fl/fl.h>

// we will need OpenGL, and OpenGL needs windows.h
#include <windows.h>
#include <cmath>
//#include "GL/gl.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "GL/glu.h"

#include "TrainView.H"
#include "TrainWindow.H"
#include "Utilities/3DUtils.H"
#include "Texture.h"
#include "Shader.h"
#include "chrono"


GLuint  fbo = 0;
GLuint  fboColorTex = 0;
GLuint  fboDepthRBO = 0;
GLuint  quadVAO = 0;
GLuint  quadVBO = 0;
Shader* postShader = nullptr;

// 紀錄 FBO 尺寸（視窗 resize 要重建）
int fboW = 0;
int fboH = 0;

// 0: 原圖, 1: Pixelization, 2: Toon, 3: Pixel+Toon
int postMode = 1;   // 先預設 Pixelization，之後你可以用 GUI 切換

static bool   gWaterInit = false;
static GLuint gVAO = 0, gVBO = 0, gIBO = 0;
static int    gIndexCount = 0;

static Shader* gWaterProg = nullptr;
static Texture2D* gTexHeight = nullptr;
static Texture2D* gTexNormal = nullptr;

struct CommonMatrices { GLuint ubo = 0; } gMats;

static const int   GRID_N = 200;       // N x N 網格
static const float GRID_S = 160.0f;    // 寬度（世界單位）

// ======= Added by GPT: spline helpers and drawing ==

// Primitive point math helpers to avoid relying on operator overloads
inline Pnt3f addP(const Pnt3f& a, const Pnt3f& b){ return Pnt3f(a.x+b.x, a.y+b.y, a.z+b.z); }
inline Pnt3f subP(const Pnt3f& a, const Pnt3f& b){ return Pnt3f(a.x-b.x, a.y-b.y, a.z-b.z); }
inline Pnt3f scaleP(const Pnt3f& a, float s){ return Pnt3f(a.x*s, a.y*s, a.z*s); }

namespace {
// safe local subdivision count
static const int kSubdiv = 40;
static const float kRailHalfWidth = 2.5f; // half-gap from center to rail line
static const int kSleeperEvery = 6; // draw a sleeper every N segments
static const float kSleeperHalf = 3.0f; // half length of sleeper (across the rails)

// Read current spline mode from UI: 1=Linear, 2=Cardinal Cubic, 3=Cubic B-Spline (TrainWindow sets these)
inline Pnt3f crossP(const Pnt3f& a, const Pnt3f& b){
    return Pnt3f(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

inline int currentSplineMode(const TrainView* tv) {
    if (!tv || !tv->tw || !tv->tw->splineBrowser) return 1;
    return tv->tw->splineBrowser->value(); // 1..3
}

inline size_t wrapIndex(const std::vector<ControlPoint>& pts, long i) {
    long n = (long)pts.size();
    long m = ((i % n) + n) % n;
    return (size_t)m;
}

// Basis for uniform cubic B-spline on [0,1]
inline Pnt3f bsplinePos(const std::vector<ControlPoint>& pts, long i, float t) {
    size_t i0 = wrapIndex(pts, i-1);
    size_t i1 = wrapIndex(pts, i);
    size_t i2 = wrapIndex(pts, i+1);
    size_t i3 = wrapIndex(pts, i+2);
    float t2 = t*t, t3 = t2*t;
    float b0 = (-t3 + 3.f*t2 - 3.f*t + 1.f) / 6.f;
    float b1 = ( 3.f*t3 - 6.f*t2 + 4.f) / 6.f;
    float b2 = (-3.f*t3 + 3.f*t2 + 3.f*t + 1.f) / 6.f;
    float b3 = ( t3 ) / 6.f;
    return addP(addP(scaleP(pts[i0].pos,b0), scaleP(pts[i1].pos,b1)), addP(scaleP(pts[i2].pos,b2), scaleP(pts[i3].pos,b3)));
}

// Tangent (derivative) for B-spline
inline Pnt3f bsplineTangent(const std::vector<ControlPoint>& pts, long i, float t) {
    size_t i0 = wrapIndex(pts, i-1);
    size_t i1 = wrapIndex(pts, i);
    size_t i2 = wrapIndex(pts, i+1);
    size_t i3 = wrapIndex(pts, i+2);
    float t2 = t*t;
    float b0 = (-3.f*t2 + 6.f*t - 3.f) / 6.f;
    float b1 = ( 9.f*t2 -12.f*t ) / 6.f;
    float b2 = (-9.f*t2 + 6.f*t + 3.f) / 6.f;
    float b3 = ( 3.f*t2 ) / 6.f;
    return addP(addP(scaleP(pts[i0].pos,b0), scaleP(pts[i1].pos,b1)), addP(scaleP(pts[i2].pos,b2), scaleP(pts[i3].pos,b3)));
}

// Cardinal cubic (Catmull-Rom when tension c=0): segment i between Pi and Pi+1
inline Pnt3f cardinalPos(const std::vector<ControlPoint>& pts, long i, float t, float tensionC = 0.0f) {
    size_t im1 = wrapIndex(pts, i-1);
    size_t i0  = wrapIndex(pts, i);
    size_t i1  = wrapIndex(pts, i+1);
    size_t i2  = wrapIndex(pts, i+2);
    Pnt3f Pm1 = pts[im1].pos, P0 = pts[i0].pos, P1 = pts[i1].pos, P2 = pts[i2].pos;
    float s = (1.f - tensionC) * 0.5f;
    Pnt3f m0 = scaleP(subP(P1, Pm1), s);
    Pnt3f m1 = scaleP(subP(P2, P0), s);
    float t2 = t*t, t3 = t2*t;
    float h00 =  2.f*t3 - 3.f*t2 + 1.f;
    float h10 =      t3 - 2.f*t2 + t;
    float h01 = -2.f*t3 + 3.f*t2;
    float h11 =      t3 -    t2;
    return addP(addP(scaleP(P0,h00), scaleP(m0,h10)), addP(scaleP(P1,h01), scaleP(m1,h11)));
}

inline Pnt3f cardinalTangent(const std::vector<ControlPoint>& pts, long i, float t, float tensionC = 0.0f) {
    size_t im1 = wrapIndex(pts, i-1);
    size_t i0  = wrapIndex(pts, i);
    size_t i1  = wrapIndex(pts, i+1);
    size_t i2  = wrapIndex(pts, i+2);
    Pnt3f Pm1 = pts[im1].pos, P0 = pts[i0].pos, P1 = pts[i1].pos, P2 = pts[i2].pos;
    float s = (1.f - tensionC) * 0.5f;
    Pnt3f m0 = scaleP(subP(P1, Pm1), s);
    Pnt3f m1 = scaleP(subP(P2, P0), s);
    float t2 = t*t;
    float dh00 = 6.f*t2 - 6.f*t;
    float dh10 = 3.f*t2 - 4.f*t + 1.f;
    float dh01 = -6.f*t2 + 6.f*t;
    float dh11 = 3.f*t2 - 2.f*t;
    return addP(addP(scaleP(P0,dh00), scaleP(m0,dh10)), addP(scaleP(P1,dh01), scaleP(m1,dh11)));
}

// Linear
inline Pnt3f linearPos(const std::vector<ControlPoint>& pts, long i, float t) {
    size_t i0 = wrapIndex(pts, i);
    size_t i1 = wrapIndex(pts, i+1);
    return addP(scaleP(pts[i0].pos, (1.f - t)), scaleP(pts[i1].pos, t));
}
inline Pnt3f linearTangent(const std::vector<ControlPoint>& pts, long i, float /*t*/) {
    size_t i0 = wrapIndex(pts, i);
    size_t i1 = wrapIndex(pts, i+1);
    return subP(pts[i1].pos, pts[i0].pos);
}

// Interpolated orientation (simply linear on control point orients)
inline Pnt3f orientLerp(const std::vector<ControlPoint>& pts, long i, float t) {
    size_t i0 = wrapIndex(pts, i);
    size_t i1 = wrapIndex(pts, i+1);
    Pnt3f o = addP(scaleP(pts[i0].orient, (1.f - t)), scaleP(pts[i1].orient, t));
    o.normalize();
    return o;
}

// Sample a point/tangent/orient on the selected curve
inline void sampleCurve(const TrainView* tv, const std::vector<ControlPoint>& pts, long seg, float t, 
                        Pnt3f& pos, Pnt3f& tangent, Pnt3f& up) {
    int mode = currentSplineMode(tv);
    if (mode == 3) { // B-spline
        pos = bsplinePos(pts, seg, t);
        tangent = bsplineTangent(pts, seg, t);
        up = orientLerp(pts, seg, t);
    } else if (mode == 2) { // Cardinal
        pos = cardinalPos(pts, seg, t, 0.0f);
        tangent = cardinalTangent(pts, seg, t, 0.0f);
        up = orientLerp(pts, seg, t);
    } else { // Linear
        pos = linearPos(pts, seg, t);
        tangent = linearTangent(pts, seg, t);
        up = orientLerp(pts, seg, t);
    }
    tangent.normalize();
}
} // namespace
// ================= Arc-length lookup table (robust uniform speed) =================
namespace {
	struct ArcTable {
		int nSeg = 0;
		int subPerSeg = 40; // sampling density per control segment
		std::vector<float> S; // cumulative arc length, size = nSeg*subPerSeg+1
		// cache to detect changes
		size_t ptsHash = 0;
	} gArc;
}

// simple hash of control points to detect edits
static size_t hashPoints(const std::vector<ControlPoint>& pts) {
	size_t h = pts.size();
	for (const auto& c : pts) {
		h ^= std::hash<int>{}(int(c.pos.x*1000)) + 0x9e3779b9 + (h<<6) + (h>>2);
		h ^= std::hash<int>{}(int(c.pos.y*1000)) + 0x9e3779b9 + (h<<6) + (h>>2);
		h ^= std::hash<int>{}(int(c.pos.z*1000)) + 0x9e3779b9 + (h<<6) + (h>>2);
	}
	return h;
}

static void buildArcTableIfNeeded(const TrainView* tv) {
	const auto& pts = tv->m_pTrack->points;
	int n = (int)pts.size();
	if (n < 2) return;
	size_t hp = hashPoints(pts);
	if (gArc.nSeg == n && gArc.ptsHash == hp && !gArc.S.empty()) return;
	gArc.nSeg = n;
	gArc.ptsHash = hp;
	int N = n * gArc.subPerSeg;
	gArc.S.assign(N+1, 0.f);
	// step du
	float du = 1.0f / gArc.subPerSeg;
	Pnt3f p0, t0, u0;
	// start from u=0 (segment 0, t=0)
	sampleCurve(tv, pts, 0, 0.f, p0, t0, u0);
	for (int i = 1; i <= N; ++i) {
		float u = i * du;
		int seg = int(floorf(u)) % n;
		float tt = u - floorf(u);
		Pnt3f p1, t1, u1;
		sampleCurve(tv, pts, seg, tt, p1, t1, u1);
		float dx = p1.x - p0.x, dy = p1.y - p0.y, dz = p1.z - p0.z;
		float ds = sqrtf(dx*dx + dy*dy + dz*dz);
		gArc.S[i] = gArc.S[i-1] + ds;
		p0 = p1;
	}
}

static inline float totalArcLen() {
	return gArc.S.empty() ? 0.f : gArc.S.back();
}

// map u -> cumulative s using the table (linear interp between samples)
static float arcSfromU(float u) {
	if (gArc.S.empty()) return 0.f;
	int N = (int)gArc.S.size() - 1;
	float x = u * gArc.subPerSeg;
	int i = (int)floorf(x);
	float a = x - i;
	i = (i % N + N) % N; // wrap
	int inext = (i+1) % (N+1);
	float s0 = gArc.S[i];
	float s1 = gArc.S[inext];
	// handle wrap at end
	if (inext == 0) s1 = gArc.S.back();
	return s0 + a * (s1 - s0);
}

// invert s->u by binary search on S (then local linear interp)
static float arcUfromS(float s) {
	if (gArc.S.empty()) return 0.f;
	float L = gArc.S.back();
	// wrap s into [0,L)
	while (s >= L) s -= L;
	while (s < 0.f) s += L;
	// binary search
	int lo = 0, hi = (int)gArc.S.size()-1;
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (gArc.S[mid] <= s) lo = mid; else hi = mid;
	}
	float s0 = gArc.S[lo], s1 = gArc.S[hi];
	float a = (s1 > s0) ? (s - s0) / (s1 - s0) : 0.f;
	float u0 = lo / float(gArc.subPerSeg);
	float u1 = hi / float(gArc.subPerSeg);
	return u0 + a * (u1 - u0);
}

// public API: advance u by distance ds (world units) using arc table
float arclenAdvance(float u, float dsWorld, const TrainView* tv) {
	buildArcTableIfNeeded(tv);
	float s = arcSfromU(u);
	return arcUfromS(s + dsWorld);
}

// ======= End helpers =======


#ifdef EXAMPLE_SOLUTION
#	include "TrainExample/TrainExample.H"
#endif


//************************************************************************
//
// * Constructor to set up the GL window
//========================================================================
TrainView::
TrainView(int x, int y, int w, int h, const char* l) 
	: Fl_Gl_Window(x,y,w,h,l)
//========================================================================
{
	mode( FL_RGB|FL_ALPHA|FL_DOUBLE | FL_STENCIL );

	resetArcball();
}

//************************************************************************
//
// * Reset the camera to look at the world
//========================================================================
void TrainView::
resetArcball()
//========================================================================
{
	// Set up the camera to look at the world
	// these parameters might seem magical, and they kindof are
	// a little trial and error goes a long way
	arcball.setup(this, 40, 250, .2f, .4f, 0);
}

//************************************************************************
//
// * FlTk Event handler for the window
//########################################################################
// TODO: 
//       if you want to make the train respond to other events 
//       (like key presses), you might want to hack this.
//########################################################################
//========================================================================
int TrainView::handle(int event)
{
	// see if the ArcBall will handle the event - if it does, 
	// then we're done
	// note: the arcball only gets the event if we're in world view
	if (tw->worldCam->value())
		if (arcball.handle(event)) 
			return 1;

	// remember what button was used
	static int last_push;

	switch(event) {
		// Mouse button being pushed event
		case FL_PUSH:
			last_push = Fl::event_button();
			// if the left button be pushed is left mouse button
			if (last_push == FL_LEFT_MOUSE  ) {
				doPick();
				damage(1);
				return 1;
			};
			break;

	   // Mouse button release event
		case FL_RELEASE: // button release
			damage(1);
			last_push = 0;
			return 1;

		// Mouse button drag event
		case FL_DRAG:

			// Compute the new control point position
			if ((last_push == FL_LEFT_MOUSE) && (selectedCube >= 0)) {
				ControlPoint* cp = &m_pTrack->points[selectedCube];

				double r1x, r1y, r1z, r2x, r2y, r2z;
				getMouseLine(r1x, r1y, r1z, r2x, r2y, r2z);

				double rx, ry, rz;
				mousePoleGo(r1x, r1y, r1z, r2x, r2y, r2z, 
								static_cast<double>(cp->pos.x), 
								static_cast<double>(cp->pos.y),
								static_cast<double>(cp->pos.z),
								rx, ry, rz,
								(Fl::event_state() & FL_CTRL) != 0);

				cp->pos.x = (float) rx;
				cp->pos.y = (float) ry;
				cp->pos.z = (float) rz;
				damage(1);
			}
			break;

		// in order to get keyboard events, we need to accept focus
		case FL_FOCUS:
			return 1;

		// every time the mouse enters this window, aggressively take focus
		case FL_ENTER:	
			focus(this);
			break;

		case FL_KEYBOARD:
		 		int k = Fl::event_key();
				int ks = Fl::event_state();
				if (k == 'p') {
					// Print out the selected control point information
					if (selectedCube >= 0) 
						printf("Selected(%d) (%g %g %g) (%g %g %g)\n",
								 selectedCube,
								 m_pTrack->points[selectedCube].pos.x,
								 m_pTrack->points[selectedCube].pos.y,
								 m_pTrack->points[selectedCube].pos.z,
								 m_pTrack->points[selectedCube].orient.x,
								 m_pTrack->points[selectedCube].orient.y,
								 m_pTrack->points[selectedCube].orient.z);
					else
						printf("Nothing Selected\n");

					return 1;
				};
				break;
	}

	return Fl_Gl_Window::handle(event);
}



//************************************************************************
//
// * this is the code that actually draws the window
//   it puts a lot of the work into other routines to simplify things
//========================================================================
void TrainView::draw()
{
    // -------- GLAD (once) --------
    static bool gl_ready = false;
    if (!gl_ready) {
        if (!gladLoadGL()) throw std::runtime_error("Could not initialize GLAD!");
        gl_ready = true;
    }

    int scrW = w();
    int scrH = h();

    // ================== FBO & Toon Post-process 資源（初始化一次） ==================
    static bool   ppInit = false;
    static GLuint fbo = 0;
    static GLuint colorTex = 0;
    static GLuint depthRBO = 0;
    static Shader* postProg = nullptr;
    static GLuint quadVAO = 0;
    static GLuint quadVBO = 0;
    static GLint  locScreenTex = -1;
    static GLint  locResolution = -1;
    static GLint  locEdgeThreshold = -1;
    static GLint  locQuantLevels = -1;

    if (!ppInit) {
        // 1) FBO
        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        // color
        glGenTextures(1, &colorTex);
        glBindTexture(GL_TEXTURE_2D, colorTex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, scrW, scrH, 0,
            GL_RGB, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
            GL_TEXTURE_2D, colorTex, 0);

        // depth + stencil
        glGenRenderbuffers(1, &depthRBO);
        glBindRenderbuffer(GL_RENDERBUFFER, depthRBO);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, scrW, scrH);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
            GL_RENDERBUFFER, depthRBO);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            fprintf(stderr, "Framebuffer not complete!\n");
        }
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        // 2) fullscreen quad
        float quadVertices[] = {
            // pos      // uv
            -1.f, -1.f, 0.f, 0.f,
             1.f, -1.f, 1.f, 0.f,
            -1.f,  1.f, 0.f, 1.f,
             1.f,  1.f, 1.f, 1.f
        };

        glGenVertexArrays(1, &quadVAO);
        glGenBuffers(1, &quadVBO);
        glBindVertexArray(quadVAO);
        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices),
            quadVertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0); // aPos
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
            4 * sizeof(float), (void*)0);

        glEnableVertexAttribArray(1); // aTexCoord
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
            4 * sizeof(float), (void*)(2 * sizeof(float)));

        glBindVertexArray(0);

        // 3) Toon 後處理 shader
        postProg = new Shader("./shaders/post.vert",
            nullptr, nullptr, nullptr,
            "./shaders/post_toon.frag");
        postProg->Use();
        locScreenTex = glGetUniformLocation(postProg->Program, "screenTex");
        locResolution = glGetUniformLocation(postProg->Program, "uResolution");
        locEdgeThreshold = glGetUniformLocation(postProg->Program, "uEdgeThreshold");
        locQuantLevels = glGetUniformLocation(postProg->Program, "uQuantLevels");
        if (locScreenTex >= 0) glUniform1i(locScreenTex, 0);
        glUseProgram(0);

        ppInit = true;
    }

    // ================== PASS 1: 把場景畫到 FBO ==================
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    glViewport(0, 0, scrW, scrH);
    glClearColor(0.f, 0.f, 0.3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // 用你原本的 projection / camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    setProjection();

    // ================== 畫場景：反射立方體 + skybox ==================
    // （下面這段就是你原本的 scene code，沒碰 post-processing 的部分）

    static bool   skyInit = false;
    static Shader* skyProg = nullptr;
    static GLuint skyVAO = 0, skyVBO = 0;
    static GLuint skyTex = 0;

    auto loadCubemapFromTextures = [](const std::vector<std::string>& faces) -> GLuint {
        GLuint texID = 0;
        glGenTextures(1, &texID);
        glBindTexture(GL_TEXTURE_CUBE_MAP, texID);

        for (int i = 0; i < (int)faces.size(); ++i) {
            Texture2D faceTex(faces[i].c_str());
            faceTex.bind(0);
            GLint w = 0, h = 0;
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
            if (w > 0 && h > 0) {
                std::vector<unsigned char> pixels(w * h * 4);
                glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                    0, GL_RGBA, w, h, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
            }
            Texture2D::unbind(0);
        }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        return texID;
        };

    if (!skyInit)
    {
        skyProg = new Shader("./shaders/simple.vert", nullptr, nullptr, nullptr,
            "./shaders/simple.frag");

        float skyboxVertices[] = {
            -1.0f,  1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,
             1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

             1.0f, -1.0f, -1.0f,
             1.0f, -1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f,  1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

            -1.0f,  1.0f, -1.0f,
             1.0f,  1.0f, -1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
             1.0f, -1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
             1.0f, -1.0f,  1.0f
        };

        glGenVertexArrays(1, &skyVAO);
        glGenBuffers(1, &skyVBO);
        glBindVertexArray(skyVAO);
        glBindBuffer(GL_ARRAY_BUFFER, skyVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices),
            skyboxVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
            3 * sizeof(float), (void*)0);
        glBindVertexArray(0);

        std::vector<std::string> faces = {
            "./images/skybox/right.jpg",
            "./images/skybox/left.jpg",
            "./images/skybox/top.jpg",
            "./images/skybox/bottom.jpg",
            "./images/skybox/front.jpg",
            "./images/skybox/back.jpg"
        };
        skyTex = loadCubemapFromTextures(faces);

        skyProg->Use();
        GLint locSB = glGetUniformLocation(skyProg->Program, "skybox");
        if (locSB >= 0) glUniform1i(locSB, 0);
        glUseProgram(0);

        skyInit = true;
    }

    // reflective cube
    static bool   cubeInit = false;
    static Shader* cubeProg = nullptr;
    static GLuint cubeVAO = 0, cubeVBO = 0;

    if (!cubeInit)
    {
        cubeProg = new Shader("./shaders/reflect.vert",
            nullptr, nullptr, nullptr,
            "./shaders/reflect.frag");
        cubeProg->Use();
        GLint locSB = glGetUniformLocation(cubeProg->Program, "skybox");
        if (locSB >= 0) glUniform1i(locSB, 0);
        glUseProgram(0);

        float cubeVertices[] = {
            // pos               // normal
            // back (-Z)
            -1.f,-1.f,-1.f,   0.f, 0.f,-1.f,
             1.f, 1.f,-1.f,   0.f, 0.f,-1.f,
             1.f,-1.f,-1.f,   0.f, 0.f,-1.f,
             1.f, 1.f,-1.f,   0.f, 0.f,-1.f,
            -1.f,-1.f,-1.f,   0.f, 0.f,-1.f,
            -1.f, 1.f,-1.f,   0.f, 0.f,-1.f,

            // front (+Z)
            -1.f,-1.f, 1.f,   0.f, 0.f, 1.f,
             1.f,-1.f, 1.f,   0.f, 0.f, 1.f,
             1.f, 1.f, 1.f,   0.f, 0.f, 1.f,
             1.f, 1.f, 1.f,   0.f, 0.f, 1.f,
            -1.f, 1.f, 1.f,   0.f, 0.f, 1.f,
            -1.f,-1.f, 1.f,   0.f, 0.f, 1.f,

            // left (-X)
            -1.f, 1.f, 1.f,  -1.f, 0.f, 0.f,
            -1.f, 1.f,-1.f,  -1.f, 0.f, 0.f,
            -1.f,-1.f,-1.f,  -1.f, 0.f, 0.f,
            -1.f,-1.f,-1.f,  -1.f, 0.f, 0.f,
            -1.f,-1.f, 1.f,  -1.f, 0.f, 0.f,
            -1.f, 1.f, 1.f,  -1.f, 0.f, 0.f,

            // right (+X)
             1.f, 1.f, 1.f,   1.f, 0.f, 0.f,
             1.f,-1.f,-1.f,   1.f, 0.f, 0.f,
             1.f, 1.f,-1.f,   1.f, 0.f, 0.f,
             1.f,-1.f,-1.f,   1.f, 0.f, 0.f,
             1.f, 1.f, 1.f,   1.f, 0.f, 0.f,
             1.f,-1.f, 1.f,   1.f, 0.f, 0.f,

             // bottom (-Y)
             -1.f,-1.f,-1.f,   0.f,-1.f, 0.f,
              1.f,-1.f,-1.f,   0.f,-1.f, 0.f,
              1.f,-1.f, 1.f,   0.f,-1.f, 0.f,
              1.f,-1.f, 1.f,   0.f,-1.f, 0.f,
             -1.f,-1.f, 1.f,   0.f,-1.f, 0.f,
             -1.f,-1.f,-1.f,   0.f,-1.f, 0.f,

             // top (+Y)
             -1.f, 1.f,-1.f,   0.f, 1.f, 0.f,
              1.f, 1.f, 1.f,   0.f, 1.f, 0.f,
              1.f, 1.f,-1.f,   0.f, 1.f, 0.f,
              1.f, 1.f, 1.f,   0.f, 1.f, 0.f,
             -1.f, 1.f,-1.f,   0.f, 1.f, 0.f,
             -1.f, 1.f, 1.f,   0.f, 1.f, 0.f
        };

        glGenVertexArrays(1, &cubeVAO);
        glGenBuffers(1, &cubeVBO);
        glBindVertexArray(cubeVAO);
        glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices),
            cubeVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
            6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
            6 * sizeof(float), (void*)(3 * sizeof(float)));
        glBindVertexArray(0);

        cubeInit = true;
    }

    // 拿相機矩陣
    GLfloat P[16], MV[16];
    glGetFloatv(GL_PROJECTION_MATRIX, P);
    glGetFloatv(GL_MODELVIEW_MATRIX, MV);

    // 先畫中間的 reflective cube
    {
        GLfloat Mmodel[16] = { 0 };
        float s = 20.0f;
        Mmodel[0] = s;
        Mmodel[5] = s;
        Mmodel[10] = s;
        Mmodel[15] = 1.f;

        cubeProg->Use();
        GLint locProj = glGetUniformLocation(cubeProg->Program, "uProjection");
        GLint locView = glGetUniformLocation(cubeProg->Program, "uView");
        GLint locModel = glGetUniformLocation(cubeProg->Program, "uModel");
        if (locProj >= 0)  glUniformMatrix4fv(locProj, 1, GL_FALSE, P);
        if (locView >= 0)  glUniformMatrix4fv(locView, 1, GL_FALSE, MV);
        if (locModel >= 0) glUniformMatrix4fv(locModel, 1, GL_FALSE, Mmodel);

        glDepthFunc(GL_LESS);
        glDisable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, skyTex);

        glBindVertexArray(cubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        glUseProgram(0);
    }

    // 再畫 skybox
    if (skyTex != 0)
    {
        GLfloat MVsky[16];
        for (int i = 0; i < 16; ++i) MVsky[i] = MV[i];
        MVsky[12] = MVsky[13] = MVsky[14] = 0.f;

        skyProg->Use();
        GLint locProj = glGetUniformLocation(skyProg->Program, "uProjection");
        GLint locView = glGetUniformLocation(skyProg->Program, "uView");
        if (locProj >= 0) glUniformMatrix4fv(locProj, 1, GL_FALSE, P);
        if (locView >= 0) glUniformMatrix4fv(locView, 1, GL_FALSE, MVsky);

        glDepthFunc(GL_LEQUAL);
        glDisable(GL_LIGHTING);
        glDisable(GL_CULL_FACE);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, skyTex);

        glBindVertexArray(skyVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        glDepthFunc(GL_LESS);
        glUseProgram(0);
    }

    // ================== PASS 2: 回螢幕，做 Toon ==================
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, scrW, scrH);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    postProg->Use();
    if (locResolution >= 0)
        glUniform2f(locResolution, (float)scrW, (float)scrH);
    if (locEdgeThreshold >= 0)
        glUniform1f(locEdgeThreshold, 0.15f);   // 邊線敏感度（可調）
    if (locQuantLevels >= 0)
        glUniform1f(locQuantLevels, 4.0f);     // 色階數量（可調）

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, colorTex);

    glBindVertexArray(quadVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glUseProgram(0);
}



//************************************************************************
//
// * UBO
//========================================================================
void TrainView::setUBO() {
	float wdt = this->pixel_w();
	float hgt = this->pixel_h();

	glm::mat4 view_matrix;
	glGetFloatv(GL_MODELVIEW_MATRIX, &view_matrix[0][0]);

	glm::mat4 projection_matrix;
	glGetFloatv(GL_PROJECTION_MATRIX, &projection_matrix[0][0]);

	glBindBuffer(GL_UNIFORM_BUFFER, this->commom_matrices->ubo);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), &projection_matrix[0][0]);
	glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), &view_matrix[0][0]);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}


//************************************************************************
//
// * This sets up both the Projection and the ModelView matrices
//   HOWEVER: it doesn't clear the projection first (the caller handles
//   that) - its important for picking
//========================================================================
void TrainView::
setProjection()
//========================================================================
{
	// Compute the aspect ratio (we'll need it)
	float aspect = static_cast<float>(w()) / static_cast<float>(h());

	// Check whether we use the world camp
	if (tw->worldCam->value())
		arcball.setProjection(false);
	// Or we use the top cam
	else if (tw->topCam->value()) {
		float wi, he;
		if (aspect >= 1) {
			wi = 110;
			he = wi / aspect;
		} 
		else {
			he = 110;
			wi = he * aspect;
		}

		// Set up the top camera drop mode to be orthogonal and set
		// up proper projection matrix
		glMatrixMode(GL_PROJECTION);
		glOrtho(-wi, wi, -he, he, 200, -200);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(-90,1,0,0);
	} 
	// Or do the train view or other view here
	//####################################################################
	// TODO: 
	// put code for train view projection here!	
	//####################################################################
	else {
#ifdef EXAMPLE_SOLUTION
		trainCamView(this,aspect);
#endif
	}
}

//************************************************************************
//
// * this draws all of the stuff in the world
//
//	NOTE: if you're drawing shadows, DO NOT set colors (otherwise, you get 
//       colored shadows). this gets called twice per draw 
//       -- once for the objects, once for the shadows
//########################################################################
// TODO: 
// if you have other objects in the world, make sure to draw them
//########################################################################
//========================================================================
void TrainView::drawStuff(bool doingShadows)
{
	return;
}
    


	// draw the train
	//####################################################################
	// TODO: 
	//	call your own train drawing code
	//####################################################################
#ifdef EXAMPLE_SOLUTION
	// don't draw the train if you're looking out the front window
	if (!tw->trainCam->value())
		drawTrain(this, doingShadows);
#endif


// 
//************************************************************************
//
// * this tries to see which control point is under the mouse
//	  (for when the mouse is clicked)
//		it uses OpenGL picking - which is always a trick
//########################################################################
// TODO: 
//		if you want to pick things other than control points, or you
//		changed how control points are drawn, you might need to change this
//########################################################################
//========================================================================
void TrainView::
doPick()
//========================================================================
{
	// since we'll need to do some GL stuff so we make this window as 
	// active window
	make_current();

	// where is the mouse?
	int mx = Fl::event_x();
	int my = Fl::event_y();

	// get the viewport - most reliable way to turn mouse coords into GL coords
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	// Set up the pick matrix on the stack - remember, FlTk is
	// upside down!
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPickMatrix((double)mx, (double)(viewport[3] - my), 5, 5, viewport);

	// now set up the projection
	setProjection();

	// now draw the objects - but really only see what we hit
	GLuint buf[100];
	glSelectBuffer(100, buf);
	glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);

	// draw the cubes, loading the names as we go
	for (size_t i = 0; i < m_pTrack->points.size(); ++i) {
		glLoadName((GLuint)(i + 1));
		m_pTrack->points[i].draw();
	}

	// go back to drawing mode, and see how picking did
	int hits = glRenderMode(GL_RENDER);
	if (hits) {
		// warning; this just grabs the first object hit - if there
		// are multiple objects, you really want to pick the closest
		// one - see the OpenGL manual 
		// remember: we load names that are one more than the index
		selectedCube = buf[3] - 1;
	}
	else // nothing hit, nothing selected
		selectedCube = -1;

	printf("Selected Cube %d\n", selectedCube);
}