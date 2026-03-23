#pragma once
#include <math.h>

struct Vec4 { float x,y,z,w; Vec4():x(0),y(0),z(0),w(1){} Vec4(float X,float Y,float Z,float W=1.0f):x(X),y(Y),z(Z),w(W){} };
struct Mat4 { float m[16]; Mat4(){ for(int i=0;i<16;++i)m[i]=0.0f; } };

inline float deg2rad(float d){ return d*3.1415926535f/180.0f; }
inline Vec4 V4(float x,float y,float z,float w=1.0f){ return Vec4(x,y,z,w); }
inline void loadI(float*M){ for(int i=0;i<16;++i)M[i]=0.0f; M[0]=M[5]=M[10]=M[15]=1.0f; }

inline Vec4 mul(const Mat4& M,const Vec4& v){
    return Vec4(
        M.m[0]*v.x + M.m[4]*v.y + M.m[8]*v.z  + M.m[12]*v.w,
        M.m[1]*v.x + M.m[5]*v.y + M.m[9]*v.z  + M.m[13]*v.w,
        M.m[2]*v.x + M.m[6]*v.y + M.m[10]*v.z + M.m[14]*v.w,
        M.m[3]*v.x + M.m[7]*v.y + M.m[11]*v.z + M.m[15]*v.w
    );
}
inline Mat4 mul(const Mat4& A,const Mat4& B){
    Mat4 R;
    for(int c=0;c<4;++c){
        for(int r=0;r<4;++r){
            R.m[c*4+r] = A.m[0*4+r]*B.m[c*4+0] + A.m[1*4+r]*B.m[c*4+1] + A.m[2*4+r]*B.m[c*4+2] + A.m[3*4+r]*B.m[c*4+3];
        }
    }
    return R;
}

inline void norm3(float v[3]){ float L=sqrtf(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]); if(L>0){ v[0]/=L; v[1]/=L; v[2]/=L; } }
inline void cross3(const float a[3],const float b[3],float r[3]){ r[0]=a[1]*b[2]-a[2]*b[1]; r[1]=a[2]*b[0]-a[0]*b[2]; r[2]=a[0]*b[1]-a[1]*b[0]; }
inline float dot3(const float a[3],const float b[3]){ return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }

inline Mat4 makePerspective(float fovy_deg,float aspect,float n,float f){
    Mat4 P; loadI(P.m);
    float t=tanf(deg2rad(fovy_deg)*0.5f);
    P.m[0]=1.0f/(aspect*t); P.m[5]=1.0f/t;
    P.m[10]=-(f+n)/(f-n); P.m[11]=-1.0f;
    P.m[14]=-(2.0f*f*n)/(f-n); P.m[15]=0.0f;
    return P;
}
inline Mat4 makeLookAt(const float eye[3],const float center[3],const float up_in[3]){
    float f[3]={center[0]-eye[0],center[1]-eye[1],center[2]-eye[2]}; norm3(f);
    float up[3]={up_in[0],up_in[1],up_in[2]}; norm3(up);
    float s[3]; cross3(f,up,s); norm3(s);
    float u[3]; cross3(s,f,u);
    Mat4 V; loadI(V.m);
    V.m[0]=s[0]; V.m[4]=s[1]; V.m[8]=s[2];
    V.m[1]=u[0]; V.m[5]=u[1]; V.m[9]=u[2];
    V.m[2]=-f[0]; V.m[6]=-f[1]; V.m[10]=-f[2];
    V.m[12]=-dot3(s,eye); V.m[13]=-dot3(u,eye); V.m[14]= dot3(f,eye);
    return V;
}
