/************************************************************************
     File:        MazeWindow.cpp

     Author:
                  Stephen Chenney, schenney@cs.wisc.edu
     Modifier
                  Yu-Chi Lai, yu-chi@cs.wisc.edu

     Comment:
                                                (c) 2001-2002 Stephen Chenney, University of Wisconsin at Madison

                                                Class header file for the MazeWindow class. The MazeWindow is
                                                the window in which the viewer's view of the maze is displayed.


     Platform:    Visio Studio.Net 2003 (converted to 2005)

*************************************************************************/

#include "MazeWindow.h"
#include <iostream>
#include <Fl/gl.h>
#include <Fl/math.h>
#include <GL/glu.h>
#include <stdio.h>
#include <cmath>

//*************************************************************************
//
// * Constructor
//=========================================================================
MazeWindow::MazeWindow(int x, int y, int width, int height, const char* label, Maze* m)
    : Fl_Gl_Window(x, y, width, height, label)
//=========================================================================
{
    maze = m;

    this->d_down = 0;
    this->x_dirMove = 0;
    this->y_dirMove = 0;
    this->d_keyDown = 0;

    // The mouse button isn't down and there is no key pressed.
    down = false;
    this->keyDown = false;
    z_key = 0;
}

//*************************************************************************
//
// * Set the maze. Also causes a redraw.
//=========================================================================
void MazeWindow::Set_Maze(Maze* m)
//=========================================================================
{
    // Change the maze
    maze = m;

    // Force a redraw
    redraw();
}

struct Vec3 {
    double x;
    double y;
    double z;
};

static inline Vec3 sub(const Vec3& a, const Vec3& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

static inline Vec3 cross(const Vec3& a, const Vec3& b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

static inline float dot(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline Vec3 normal(const Vec3& a) {
    double L = std::sqrt(dot(a, a));
    return {a.x / L, a.y / L, a.z / L};
}

//*************************************************************************
//
// * draw() method invoked whenever the view changes or the window
//   otherwise needs to be redrawn.
//=========================================================================
void MazeWindow::draw(void)
//=========================================================================
{
    float focal_length;

    if (!valid()) {
        // The OpenGL context may have been changed
        // Set up the viewport to fill the window.
        glViewport(0, 0, w(), h());

        // We are using orthogonal viewing for 2D. This puts 0,0 in the
        // middle of the screen, and makes the image size in view space
        // the same size as the window.
        gluOrtho2D(-w() * 0.5, w() * 0.5, -h() * 0.5, h() * 0.5);

        // Sets the clear color to black.
        glClearColor(0.0, 0.0, 0.0, 1.0);
    }

    // Clear the screen.
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /*gluOrtho2D(-w() * 0.5, w() * 0.5, -h() * 0.5, h() * 0.5);*/

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_DEPTH_BUFFER_BIT);
    
    glBegin(GL_QUADS);
    // Draw the "floor". It is an infinite plane perpendicular to
    // vertical, so we know it projects to cover the entire bottom
    // half of the screen. Walls of the maze will be drawn over the top
    // of it.
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-w() * 0.5f, -h() * 0.5f);
    glVertex2f(w() * 0.5f, -h() * 0.5f );
    glVertex2f(w() * 0.5f, 0.0);
    glVertex2f(-w() * 0.5f, 0.0);

    // Draw the ceiling. It will project to the entire top half
    // of the window.
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(w() * 0.5f, h() * 0.5f );
    glVertex2f(-w() * 0.5f, h() * 0.5f );
    glVertex2f(-w() * 0.5f, 0.0);
    glVertex2f(w() * 0.5f, 0.0);
    glEnd();

    // only when floor and cell is draw othere can compare Depth

    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    if (maze) {
        // Set the focal length. We can do this because we know the
        // field of view and the size of the image in view space. Note
        // the static member function of the Maze class for converting
        // radians to degrees. There is also one defined for going backwards.
        focal_length = w() / (float)(2.0 * tan(Maze::To_Radians(maze->viewer_fov) * 0.5));

        // Draw the 3D view of the maze (the visible walls.) You write this.
        // Note that all the information that is required to do the
        // transformations and projection is contained in the Maze class,
        // plus the focal length.

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        double aspect = static_cast<double>(this->w()) / static_cast<double>(this->h());

        // tan only take radians
        float fovyRad = (this->maze->viewer_fov) * M_PI / 180.0;

        float Near = 0.01;                        // is distance so it is positive
        float Far = 200;                          // is distance so it is positive
        float Top = Near * std::tan(fovyRad / 2); // in y axis
        float Bottom = -Top;
        float Right = Top * aspect; // in x axis aspexct is windows x/y
        float Left = -Right;

        float perspectiveMatirx[16] = {
            2 * Near / (Right - Left),
            0,
            0,
            0,
            0,
            2 * Near / (Top - Bottom),
            0,
            0,
            (Right + Left) / (Right - Left),
            (Top + Bottom) / (Top - Bottom),
            -(Far + Near) / (Far - Near),
            -1,
            0,
            0,
            -2 * Far * Near / (Far - Near),
            0};
        /*gluPerspective(this->maze->viewer_fov, aspect, 0.01, 200);*/
        glMultMatrixf(perspectiveMatirx);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        float viewer_pos[3] = {maze->viewer_posn[Maze::Y], 0.0f, maze->viewer_posn[Maze::X]};

        Vec3 eyePosition{viewer_pos[Maze::X], viewer_pos[Maze::Y], viewer_pos[Maze::Z]};

        Vec3 viewDirectionVec{
            viewer_pos[Maze::X] + sin(Maze::To_Radians(maze->viewer_dir)), viewer_pos[Maze::Y], viewer_pos[Maze::Z] + cos(Maze::To_Radians(maze->viewer_dir))};

        Vec3 up{0.0f, 1.0f, 0.0f};

        Vec3 forward{eyePosition.x - viewDirectionVec.x, eyePosition.y - viewDirectionVec.y, eyePosition.z - viewDirectionVec.z};

        Vec3 forNormal = normal(forward);

        Vec3 leftNormal = normal(cross(up, forNormal)); // if is cross(forNormal, up) will be right-hand space

        Vec3 upNormal = normal(up);

        // you can see the matirx in https://registry.khronos.org/OpenGL-Refpages/gl2.1/xhtml/gluLookAt.xml
        // the matirx in web site is no column-major
        float viewMatirx[16] = {
            leftNormal.x,
            upNormal.x,
            forNormal.x,
            0,
            leftNormal.y,
            upNormal.y,
            forNormal.y,
            0,
            leftNormal.z,
            upNormal.z,
            forNormal.z,
            0,
            -dot(eyePosition, leftNormal),
            -dot(eyePosition, upNormal),
            -dot(eyePosition, forNormal),
            1};

        // gluLookAt(
        //    viewer_pos[Maze::X], viewer_pos[Maze::Y], viewer_pos[Maze::Z],
        //    viewer_pos[Maze::X] + sin(Maze::To_Radians(maze->viewer_dir)),
        //    viewer_pos[Maze::Y],
        //    viewer_pos[Maze::Z] + cos(Maze::To_Radians(maze->viewer_dir)),
        //    0.0f, 1.0f, 0.0f);
        //
        glMultMatrixf(viewMatirx);
        maze->Draw_View(focal_length);
    }
}

//*************************************************************************
//
// *
//=========================================================================
bool MazeWindow::Drag(float dt)
//=========================================================================
{
    float x_move, y_move, z_move;

    if (down) {
        int dx = x_down - x_last;
        int dy = y_down - y_last;
        float dist;

        // Set the viewing direction based on horizontal mouse motion.
        maze->Set_View_Dir(d_down + 360.0f * dx / (float)w());

        // Set the viewer's linear motion based on a speed (derived from
        // vertical mouse motion), the elapsed time and the viewing direction.
        dist = 10.0f * dt * dy / (float)h();
        x_move = dist * (float)cos(Maze::To_Radians(maze->viewer_dir));
        y_move = dist * (float)sin(Maze::To_Radians(maze->viewer_dir));
    } else {
        x_move = 0.0;
        y_move = 0.0;
    }

    // Update the z posn
    z_move = z_key * 0.1f;
    z_key = 0;

    // Tell the maze how much the view has moved. It may restrict the motion
    // if it tries to go through walls.
    maze->Move_View_Posn(x_move, y_move, z_move);

    return true;
}

//*************************************************************************
//
// *
//=========================================================================
bool MazeWindow::KeyEvent(float dt)
//=========================================================================
{
    float speed = 0.1f;
    maze->Set_View_Dir(maze->viewer_dir + d_keyDown);
    maze->Move_View_Posn(speed * x_dirMove, speed * y_dirMove, 0);

    return true;
}
//*************************************************************************
//
// *
//=========================================================================
bool MazeWindow::Update(float dt)
//=========================================================================
{
    // Update the view

    if (down || z_key) // Only do anything if the mouse button is down.
        return Drag(dt);
    if (keyDown)
        return KeyEvent(dt);

    // Nothing changed, so no need for a redraw.
    return false;
}

//*************************************************************************
//
// *
//=========================================================================
int MazeWindow::handle(int event)
//=========================================================================
{
    if (!maze)
        return Fl_Gl_Window::handle(event);

    // Event handling routine.
    switch (event) {
    case FL_PUSH:
        down = true;
        x_last = x_down = Fl::event_x();
        y_last = y_down = Fl::event_y();
        d_down = maze->viewer_dir;
        return 1;
    case FL_DRAG:
        x_last = Fl::event_x();
        y_last = Fl::event_y();
        return 1;
    case FL_RELEASE:
        down = false;
        return 1;
    case FL_KEYDOWN:
        keyDown = true;
        if (Fl::event_key() == 'w') {
            x_dirMove = (float)cos(Maze::To_Radians(maze->viewer_dir));
            y_dirMove = (float)sin(Maze::To_Radians(maze->viewer_dir));
            return 1;
        }
        if (Fl::event_key() == 's') {
            x_dirMove = -(float)cos(Maze::To_Radians(maze->viewer_dir));
            y_dirMove = -(float)sin(Maze::To_Radians(maze->viewer_dir));
            return 1;
        }
        if (Fl::event_key() == 'a') {
            x_dirMove = (float)cos(Maze::To_Radians((double)maze->viewer_dir + 90.0));
            y_dirMove = (float)sin(Maze::To_Radians((double)maze->viewer_dir + 90.0));
            return 1;
        }
        if (Fl::event_key() == 'd') {
            x_dirMove = (float)cos(Maze::To_Radians((double)maze->viewer_dir - 90.0));
            y_dirMove = (float)sin(Maze::To_Radians((double)maze->viewer_dir - 90.0));
            return 1;
        }
        if (Fl::event_key() == FL_Right) {
            d_keyDown = -2.0f;
            return 1;
        }
        if (Fl::event_key() == FL_Left) {
            d_keyDown = 2.0f;
            return 1;
        }
        if (Fl::event_key() == FL_Enter) {
            if (this->fakeJamp == 0.0f) {
                this->fakeJamp = this->h() * 0.1f;
            }
        }
        return Fl_Gl_Window::handle(event);
    case FL_KEYUP:
        keyDown = false;
        x_dirMove = 0.0f;
        y_dirMove = 0.0f;
        d_keyDown = 0.0f;
        return 1;
    case FL_FOCUS:
    case FL_UNFOCUS:
        return 1;
    }

    // Pass any other event types on the superclass.
    return Fl_Gl_Window::handle(event);
}
