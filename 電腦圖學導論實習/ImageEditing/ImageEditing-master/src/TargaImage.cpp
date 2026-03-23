///////////////////////////////////////////////////////////////////////////////
//
//      TargaImage.cpp                          Author:     Stephen Chenney
//                                              Modified:   Eric McDaniel
//                                              Date:       Fall 2004
//
//      Implementation of TargaImage methods.  You must implement the image
//  modification functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "Globals.h"
#include "TargaImage.h"
#include "libtarga.h"
#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// constants
const int           RED             = 0;                // red channel
const int           GREEN           = 1;                // green channel
const int           BLUE            = 2;                // blue channel
const unsigned char BACKGROUND[3]   = { 0, 0, 0 };      // background color


// Computes n choose s, efficiently
double Binomial(int n, int s)
{
    double        res;

    res = 1;
    for (int i = 1 ; i <= s ; i++)
        res = (n - i + 1) * res / i ;

    return res;
}// Binomial


///////////////////////////////////////////////////////////////////////////////
//
//      Constructor.  Initialize member variables.
//
///////////////////////////////////////////////////////////////////////////////
TargaImage::TargaImage() : width(0), height(0), data(NULL)
{}// TargaImage

///////////////////////////////////////////////////////////////////////////////
//
//      Constructor.  Initialize member variables.
//
///////////////////////////////////////////////////////////////////////////////
TargaImage::TargaImage(int w, int h) : width(w), height(h)
{
   data = new unsigned char[width * height * 4];
   ClearToBlack();
}// TargaImage



///////////////////////////////////////////////////////////////////////////////
//
//      Constructor.  Initialize member variables to values given.
//
///////////////////////////////////////////////////////////////////////////////
TargaImage::TargaImage(int w, int h, unsigned char *d)
{
    int i;

    width = w;
    height = h;
    data = new unsigned char[width * height * 4];

    for (i = 0; i < width * height * 4; i++)
	    data[i] = d[i];
}// TargaImage

///////////////////////////////////////////////////////////////////////////////
//
//      Copy Constructor.  Initialize member to that of input
//
///////////////////////////////////////////////////////////////////////////////
TargaImage::TargaImage(const TargaImage& image) 
{
   width = image.width;
   height = image.height;
   data = NULL; 
   if (image.data != NULL) {
      data = new unsigned char[width * height * 4];
      memcpy(data, image.data, sizeof(unsigned char) * width * height * 4);
   }
}


///////////////////////////////////////////////////////////////////////////////
//
//      Destructor.  Free image memory.
//
///////////////////////////////////////////////////////////////////////////////
TargaImage::~TargaImage()
{
    if (data)
        delete[] data;
}// ~TargaImage


///////////////////////////////////////////////////////////////////////////////
//
//      Converts an image to RGB form, and returns the rgb pixel data - 24 
//  bits per pixel. The returned space should be deleted when no longer 
//  required.
//
///////////////////////////////////////////////////////////////////////////////
unsigned char* TargaImage::To_RGB(void)
{
    unsigned char   *rgb = new unsigned char[width * height * 3];
    int		    i, j;

    if (! data)
	    return NULL;

    // Divide out the alpha
    for (i = 0 ; i < height ; i++)
    {
	    int in_offset = i * width * 4;
	    int out_offset = i * width * 3;

	    for (j = 0 ; j < width ; j++)
        {
	        RGBA_To_RGB(data + (in_offset + j*4), rgb + (out_offset + j*3));
	    }
    }

    return rgb;
}// TargaImage


///////////////////////////////////////////////////////////////////////////////
//
//      Save the image to a targa file. Returns 1 on success, 0 on failure.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Save_Image(const char *filename)
{
    TargaImage	*out_image = Reverse_Rows();

    if (! out_image)
	    return false;

    if (!tga_write_raw(filename, width, height, out_image->data, TGA_TRUECOLOR_32))
    {
	    cout << "TGA Save Error: %s\n", tga_error_string(tga_get_last_error());
	    return false;
    }

    delete out_image;

    return true;
}// Save_Image


///////////////////////////////////////////////////////////////////////////////
//
//      Load a targa image from a file.  Return a new TargaImage object which 
//  must be deleted by caller.  Return NULL on failure.
//
///////////////////////////////////////////////////////////////////////////////
TargaImage* TargaImage::Load_Image(char *filename)
{
    unsigned char   *temp_data;
    TargaImage	    *temp_image;
    TargaImage	    *result;
    int		        width, height;

    if (!filename)
    {
        cout << "No filename given." << endl;
        return NULL;
    }// if

    temp_data = (unsigned char*)tga_load(filename, &width, &height, TGA_TRUECOLOR_32);
    if (!temp_data)
    {
        cout << "TGA Error: %s\n", tga_error_string(tga_get_last_error());
	    width = height = 0;
	    return NULL;
    }
    temp_image = new TargaImage(width, height, temp_data);
    free(temp_data);

    result = temp_image->Reverse_Rows();

    delete temp_image;

    return result;
}// Load_Image


///////////////////////////////////////////////////////////////////////////////
//
//      Convert image to grayscale.  Red, green, and blue channels should all 
//  contain grayscale value.  Alpha channel shoould be left unchanged.  Return
//  success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::To_Grayscale()
{
    if (!data) return false;

    // ITU-R BT.601 灰階權重
    const float wr = 0.299f, wg = 0.587f, wb = 0.114f;

    const int N = width * height * 4;
    for (int i = 0; i < N; i += 4) {
        unsigned char* px = data + i;
        const unsigned char a = px[3];

        if (a == 0) {
            // 完全透明：預乘下 RGB 應為 0，直接維持
            px[0] = px[1] = px[2] = 0;
            continue;
        }

        // 1) 解預乘：還原未預乘的真實 RGB（0..255）
        const float inv_a = 255.0f / (float)a;
        const float r = px[0] * inv_a;
        const float g = px[1] * inv_a;
        const float b = px[2] * inv_a;

        // 2) 計算灰階亮度（未預乘）
        const float y = wr * r + wg * g + wb * b;

        // 3) 乘回 alpha，存回「預乘 RGB」，alpha 值本身不變
        const float scale = (float)a / 255.0f;
        int gy = (int)floorf(y * scale + 0.5f);
        if (gy < 0) gy = 0; else if (gy > 255) gy = 255;

        px[0] = (unsigned char)gy;
        px[1] = (unsigned char)gy;
        px[2] = (unsigned char)gy;
        // px[3] = a; // 保留原 alpha
    }

    return true;
}// To_Grayscale


///////////////////////////////////////////////////////////////////////////////
//
//  Convert the image to an 8 bit image using uniform quantization.  Return 
//  success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Quant_Uniform()
{
    if (!data) return false;

    const int N = width * height * 4;

    for (int i = 0; i < N; i += 4) {
        unsigned char* px = data + i;
        const int a = px[3];

        // 若完全透明，維持全 0（常見的預乘慣例）
        if (a == 0) {
            px[0] = px[1] = px[2] = 0;
            continue;
        }

        // 解預乘：拿回真實 RGB（0..255）
        const float inv_a = 255.0f / (float)a;
        float r = px[0] * inv_a;
        float g = px[1] * inv_a;
        float b = px[2] * inv_a;

        // ---- 3-3-2 量化：取最近層級（四捨五入）----
        // 層數：R,G=8 階；B=4 階
        int r_q = (int)floorf(r * 7.0f / 255.0f + 0.5f); // 0..7
        int g_q = (int)floorf(g * 7.0f / 255.0f + 0.5f); // 0..7
        int b_q = (int)floorf(b * 3.0f / 255.0f + 0.5f); // 0..3

        // 回映射到 0..255（用層中心近似）
        float r_out = (r_q * 255.0f) / 7.0f;
        float g_out = (g_q * 255.0f) / 7.0f;
        float b_out = (b_q * 255.0f) / 3.0f;

        // 乘回 alpha，寫回預乘 RGB；alpha 保留
        const float scale = (float)a / 255.0f;
        int R = (int)floorf(r_out * scale + 0.5f);
        int G = (int)floorf(g_out * scale + 0.5f);
        int B = (int)floorf(b_out * scale + 0.5f);

        px[0] = (unsigned char)(R < 0 ? 0 : (R > 255 ? 255 : R));
        px[1] = (unsigned char)(G < 0 ? 0 : (G > 255 ? 255 : G));
        px[2] = (unsigned char)(B < 0 ? 0 : (B > 255 ? 255 : B));
        // px[3] = a;
    }

    return true;
}// Quant_Uniform


///////////////////////////////////////////////////////////////////////////////
//
//      Convert the image to an 8 bit image using populosity quantization.  
//  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Quant_Populosity()
{
    ClearToBlack();
    return false;
}// Quant_Populosity


///////////////////////////////////////////////////////////////////////////////
//
//      Dither the image using a threshold of 1/2.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Dither_Threshold()
{
    ClearToBlack();
    return false;
}// Dither_Threshold


///////////////////////////////////////////////////////////////////////////////
//
//      Dither image using random dithering.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Dither_Random()
{
    ClearToBlack();
    return false;
}// Dither_Random


///////////////////////////////////////////////////////////////////////////////
//
//      Perform Floyd-Steinberg dithering on the image.  Return success of 
//  operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Dither_FS()
{
    ClearToBlack();
    return false;
}// Dither_FS


///////////////////////////////////////////////////////////////////////////////
//
//      Dither the image while conserving the average brightness.  Return 
//  success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Dither_Bright()
{
    ClearToBlack();
    return false;
}// Dither_Bright


///////////////////////////////////////////////////////////////////////////////
//
//      Perform clustered differing of the image.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Dither_Cluster()
{
    if (!data) return false;

    // 4x4 Bayer/cluster 矩陣（0..15），轉成 0..255 的門檻
    // 若課上提供了不同矩陣，只要把 m16 換掉即可。
    static const int m16_raw[4][4] = {
        { 0,  8,  2, 10},
        {12,  4, 14,  6},
        { 3, 11,  1,  9},
        {15,  7, 13,  5}
    };
    unsigned char thresh[4][4];
    for (int y = 0; y < 4; ++y)
        for (int x = 0; x < 4; ++x) {
            // 常見作法： (k+0.5)/16 * 255  當作門檻
            float t = ((float)m16_raw[y][x] + 0.5f) * (255.0f / 16.0f);
            int   v = (int)floorf(t + 0.5f);
            if (v < 0) v = 0; else if (v > 255) v = 255;
            thresh[y][x] = (unsigned char)v;
        }

    const float wr = 0.299f, wg = 0.587f, wb = 0.114f;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = (y * width + x) * 4;

            const int a = data[idx + 3];
            if (a == 0) {
                data[idx + 0] = data[idx + 1] = data[idx + 2] = 0;
                continue;
            }

            // 解預乘 → 灰階
            const float inv_a = 255.0f / (float)a;
            float r = data[idx + 0] * inv_a;
            float g = data[idx + 1] * inv_a;
            float b = data[idx + 2] * inv_a;
            float I = wr * r + wg * g + wb * b;           // 0..255 灰階

            // 比對 4x4 門檻
            unsigned char T = thresh[y & 3][x & 3];
            float v = (I >= T) ? 255.0f : 0.0f;

            // 乘回 alpha → 寫回預乘 RGB（黑/白）
            const float scale = (float)a / 255.0f;
            int out = (int)floorf(v * scale + 0.5f);
            if (out < 0) out = 0; else if (out > 255) out = 255;

            data[idx + 0] = data[idx + 1] = data[idx + 2] = (unsigned char)out;
            // data[idx+3] = a;
        }
    }
    return true;
}// Dither_Cluster


///////////////////////////////////////////////////////////////////////////////
//
//  Convert the image to an 8 bit image using Floyd-Steinberg dithering over
//  a uniform quantization - the same quantization as in Quant_Uniform.
//  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Dither_Color()
{
    ClearToBlack();
    return false;
}// Dither_Color


///////////////////////////////////////////////////////////////////////////////
//
//      Composite the current image over the given image.  Return success of 
//  operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Comp_Over(TargaImage* pImage)
{
    if (width != pImage->width || height != pImage->height)
    {
        cout <<  "Comp_Over: Images not the same size\n";
        return false;
    }

    ClearToBlack();
    return false;
}// Comp_Over


///////////////////////////////////////////////////////////////////////////////
//
//      Composite this image "in" the given image.  See lecture notes for 
//  details.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Comp_In(TargaImage* pImage)
{
    if (width != pImage->width || height != pImage->height)
    {
        cout << "Comp_In: Images not the same size\n";
        return false;
    }

    ClearToBlack();
    return false;
}// Comp_In


///////////////////////////////////////////////////////////////////////////////
//
//      Composite this image "out" the given image.  See lecture notes for 
//  details.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Comp_Out(TargaImage* pImage)
{
    if (width != pImage->width || height != pImage->height)
    {
        cout << "Comp_Out: Images not the same size\n";
        return false;
    }

    ClearToBlack();
    return false;
}// Comp_Out


///////////////////////////////////////////////////////////////////////////////
//
//      Composite current image "atop" given image.  Return success of 
//  operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Comp_Atop(TargaImage* pImage)
{
    if (width != pImage->width || height != pImage->height)
    {
        cout << "Comp_Atop: Images not the same size\n";
        return false;
    }

    ClearToBlack();
    return false;
}// Comp_Atop


///////////////////////////////////////////////////////////////////////////////
//
//      Composite this image with given image using exclusive or (XOR).  Return
//  success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Comp_Xor(TargaImage* pImage)
{
    if (width != pImage->width || height != pImage->height)
    {
        cout << "Comp_Xor: Images not the same size\n";
        return false;
    }

    ClearToBlack();
    return false;
}// Comp_Xor


///////////////////////////////////////////////////////////////////////////////
//
//      Calculate the difference bewteen this imag and the given one.  Image 
//  dimensions must be equal.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Difference(TargaImage* pImage)
{
    if (!pImage)
        return false;

    if (width != pImage->width || height != pImage->height)
    {
        cout << "Difference: Images not the same size\n";
        return false;
    }// if

    for (int i = 0 ; i < width * height * 4 ; i += 4)
    {
        unsigned char        rgb1[3];
        unsigned char        rgb2[3];

        RGBA_To_RGB(data + i, rgb1);
        RGBA_To_RGB(pImage->data + i, rgb2);

        data[i] = abs(rgb1[0] - rgb2[0]);
        data[i+1] = abs(rgb1[1] - rgb2[1]);
        data[i+2] = abs(rgb1[2] - rgb2[2]);
        data[i+3] = 255;
    }

    return true;
}// Difference


///////////////////////////////////////////////////////////////////////////////
//
//      Perform 5x5 box filter on this image.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Filter_Box()
{
    if (!data) return false;

    const int W = width, H = height;
    const int stride = 4;

    // 來源備份（避免就地覆寫造成讀寫互相影響）
    std::vector<unsigned char> src(W * H * stride);
    memcpy(src.data(), data, W * H * stride);

    auto clamp = [&](int v, int lo, int hi) { return v < lo ? lo : (v > hi ? hi : v); };

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            float acc[3] = { 0.f, 0.f, 0.f };

            // 5x5 等權重，加總後除以 25
            for (int j = -2; j <= 2; ++j) {
                int yy = clamp(y + j, 0, H - 1);
                for (int i = -2; i <= 2; ++i) {
                    int xx = clamp(x + i, 0, W - 1);
                    int si = (yy * W + xx) * stride;
                    acc[0] += src[si + 0];
                    acc[1] += src[si + 1];
                    acc[2] += src[si + 2];
                }
            }

            int di = (y * W + x) * stride;
            data[di + 0] = (unsigned char)std::min(255, std::max(0, (int)std::floor(acc[0] / 25.f + 0.5f)));
            data[di + 1] = (unsigned char)std::min(255, std::max(0, (int)std::floor(acc[1] / 25.f + 0.5f)));
            data[di + 2] = (unsigned char)std::min(255, std::max(0, (int)std::floor(acc[2] / 25.f + 0.5f)));
            // Alpha 不過濾，直接保留中心像素 alpha（依專案說明）
            data[di + 3] = src[di + 3];
        }
    }
    return true;
}// Filter_Box


///////////////////////////////////////////////////////////////////////////////
//
//      Perform 5x5 Bartlett filter on this image.  Return success of 
//  operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Filter_Bartlett()
{
    ClearToBlack();
    return false;
}// Filter_Bartlett


///////////////////////////////////////////////////////////////////////////////
//
//      Perform 5x5 Gaussian filter on this image.  Return success of 
//  operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Filter_Gaussian()
{
    ClearToBlack();
    return false;
}// Filter_Gaussian

///////////////////////////////////////////////////////////////////////////////
//
//      Perform NxN Gaussian filter on this image.  Return success of 
//  operation.
//
///////////////////////////////////////////////////////////////////////////////

bool TargaImage::Filter_Gaussian_N( unsigned int N )
{
    ClearToBlack();
   return false;
}// Filter_Gaussian_N


///////////////////////////////////////////////////////////////////////////////
//
//      Perform 5x5 edge detect (high pass) filter on this image.  Return 
//  success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Filter_Edge()
{
    ClearToBlack();
    return false;
}// Filter_Edge


///////////////////////////////////////////////////////////////////////////////
//
//      Perform a 5x5 enhancement filter to this image.  Return success of 
//  operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Filter_Enhance()
{
    ClearToBlack();
    return false;
}// Filter_Enhance


///////////////////////////////////////////////////////////////////////////////
//
//      Run simplified version of Hertzmann's painterly image filter.
//      You probably will want to use the Draw_Stroke funciton and the
//      Stroke class to help.
// Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::NPR_Paint()
{
    ClearToBlack();
    return false;
}



///////////////////////////////////////////////////////////////////////////////
//
//      Halve the dimensions of this image.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Half_Size()
{
    if (!data || width < 1 || height < 1) return false;

    const int W = width, H = height;
    const int stride = 4;
    const int W2 = W / 2;
    const int H2 = H / 2;

    if (W2 == 0 || H2 == 0) return false;

    // 來源備份
    std::vector<unsigned char> src(W * H * stride);
    memcpy(src.data(), data, W * H * stride);

    std::vector<unsigned char> out(W2 * H2 * stride);

    // 3x3 Bartlett 權重
    const float k[3][3] = {
        {1.f / 16.f, 1.f / 8.f,  1.f / 16.f},
        {1.f / 8.f,  1.f / 4.f,  1.f / 8.f },
        {1.f / 16.f, 1.f / 8.f,  1.f / 16.f}
    };

    auto clamp = [&](int v, int lo, int hi) { return v < lo ? lo : (v > hi ? hi : v); };

    for (int j = 0; j < H2; ++j) {
        for (int i = 0; i < W2; ++i) {
            // 對應到輸入中心 (2i, 2j)
            int cx = 2 * i;
            int cy = 2 * j;

            float acc[4] = { 0.f, 0.f, 0.f, 0.f };

            for (int dj = -1; dj <= 1; ++dj) {
                int yy = clamp(cy + dj, 0, H - 1);
                for (int di = -1; di <= 1; ++di) {
                    int xx = clamp(cx + di, 0, W - 1);
                    float w = k[dj + 1][di + 1];

                    int si = (yy * W + xx) * stride;
                    acc[0] += w * src[si + 0];
                    acc[1] += w * src[si + 1];
                    acc[2] += w * src[si + 2];
                    acc[3] += w * src[si + 3]; // Resizing 也作用在 alpha
                }
            }

            int di_out = (j * W2 + i) * stride;
            out[di_out + 0] = (unsigned char)std::min(255, std::max(0, (int)std::floor(acc[0] + 0.5f)));
            out[di_out + 1] = (unsigned char)std::min(255, std::max(0, (int)std::floor(acc[1] + 0.5f)));
            out[di_out + 2] = (unsigned char)std::min(255, std::max(0, (int)std::floor(acc[2] + 0.5f)));
            out[di_out + 3] = (unsigned char)std::min(255, std::max(0, (int)std::floor(acc[3] + 0.5f)));
        }
    }

    // 取代原圖
    delete[] data;
    data = new unsigned char[W2 * H2 * stride];
    memcpy(data, out.data(), W2 * H2 * stride);
    width = W2;
    height = H2;

    return true;
}// Half_Size


///////////////////////////////////////////////////////////////////////////////
//
//      Double the dimensions of this image.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Double_Size()
{
    ClearToBlack();
    return false;
}// Double_Size


///////////////////////////////////////////////////////////////////////////////
//
//      Scale the image dimensions by the given factor.  The given factor is 
//  assumed to be greater than one.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Resize(float scale)
{
    ClearToBlack();
    return false;
}// Resize


//////////////////////////////////////////////////////////////////////////////
//
//      Rotate the image clockwise by the given angle.  Do not resize the 
//  image.  Return success of operation.
//
///////////////////////////////////////////////////////////////////////////////
bool TargaImage::Rotate(float angleDegrees)
{
    ClearToBlack();
    return false;
}// Rotate


//////////////////////////////////////////////////////////////////////////////
//
//      Given a single RGBA pixel return, via the second argument, the RGB
//      equivalent composited with a black background.
//
///////////////////////////////////////////////////////////////////////////////
void TargaImage::RGBA_To_RGB(unsigned char *rgba, unsigned char *rgb)
{
    const unsigned char	BACKGROUND[3] = { 0, 0, 0 };

    unsigned char  alpha = rgba[3];

    if (alpha == 0)
    {
        rgb[0] = BACKGROUND[0];
        rgb[1] = BACKGROUND[1];
        rgb[2] = BACKGROUND[2];
    }
    else
    {
	    float	alpha_scale = (float)255 / (float)alpha;
	    int	val;
	    int	i;

	    for (i = 0 ; i < 3 ; i++)
	    {
	        val = (int)floor(rgba[i] * alpha_scale);
	        if (val < 0)
		    rgb[i] = 0;
	        else if (val > 255)
		    rgb[i] = 255;
	        else
		    rgb[i] = val;
	    }
    }
}// RGA_To_RGB


///////////////////////////////////////////////////////////////////////////////
//
//      Copy this into a new image, reversing the rows as it goes. A pointer
//  to the new image is returned.
//
///////////////////////////////////////////////////////////////////////////////
TargaImage* TargaImage::Reverse_Rows(void)
{
    unsigned char   *dest = new unsigned char[width * height * 4];
    TargaImage	    *result;
    int 	        i, j;

    if (! data)
    	return NULL;

    for (i = 0 ; i < height ; i++)
    {
	    int in_offset = (height - i - 1) * width * 4;
	    int out_offset = i * width * 4;

	    for (j = 0 ; j < width ; j++)
        {
	        dest[out_offset + j * 4] = data[in_offset + j * 4];
	        dest[out_offset + j * 4 + 1] = data[in_offset + j * 4 + 1];
	        dest[out_offset + j * 4 + 2] = data[in_offset + j * 4 + 2];
	        dest[out_offset + j * 4 + 3] = data[in_offset + j * 4 + 3];
        }
    }

    result = new TargaImage(width, height, dest);
    delete[] dest;
    return result;
}// Reverse_Rows


///////////////////////////////////////////////////////////////////////////////
//
//      Clear the image to all black.
//
///////////////////////////////////////////////////////////////////////////////
void TargaImage::ClearToBlack()
{
    memset(data, 0, width * height * 4);
}// ClearToBlack


///////////////////////////////////////////////////////////////////////////////
//
//      Helper function for the painterly filter; paint a stroke at
// the given location
//
///////////////////////////////////////////////////////////////////////////////
void TargaImage::Paint_Stroke(const Stroke& s) {
   int radius_squared = (int)s.radius * (int)s.radius;
   for (int x_off = -((int)s.radius); x_off <= (int)s.radius; x_off++) {
      for (int y_off = -((int)s.radius); y_off <= (int)s.radius; y_off++) {
         int x_loc = (int)s.x + x_off;
         int y_loc = (int)s.y + y_off;
         // are we inside the circle, and inside the image?
         if ((x_loc >= 0 && x_loc < width && y_loc >= 0 && y_loc < height)) {
            int dist_squared = x_off * x_off + y_off * y_off;
            if (dist_squared <= radius_squared) {
               data[(y_loc * width + x_loc) * 4 + 0] = s.r;
               data[(y_loc * width + x_loc) * 4 + 1] = s.g;
               data[(y_loc * width + x_loc) * 4 + 2] = s.b;
               data[(y_loc * width + x_loc) * 4 + 3] = s.a;
            } else if (dist_squared == radius_squared + 1) {
               data[(y_loc * width + x_loc) * 4 + 0] = 
                  (data[(y_loc * width + x_loc) * 4 + 0] + s.r) / 2;
               data[(y_loc * width + x_loc) * 4 + 1] = 
                  (data[(y_loc * width + x_loc) * 4 + 1] + s.g) / 2;
               data[(y_loc * width + x_loc) * 4 + 2] = 
                  (data[(y_loc * width + x_loc) * 4 + 2] + s.b) / 2;
               data[(y_loc * width + x_loc) * 4 + 3] = 
                  (data[(y_loc * width + x_loc) * 4 + 3] + s.a) / 2;
            }
         }
      }
   }
}


///////////////////////////////////////////////////////////////////////////////
//
//      Build a Stroke
//
///////////////////////////////////////////////////////////////////////////////
Stroke::Stroke() {}

///////////////////////////////////////////////////////////////////////////////
//
//      Build a Stroke
//
///////////////////////////////////////////////////////////////////////////////
Stroke::Stroke(unsigned int iradius, unsigned int ix, unsigned int iy,
               unsigned char ir, unsigned char ig, unsigned char ib, unsigned char ia) :
   radius(iradius),x(ix),y(iy),r(ir),g(ig),b(ib),a(ia)
{
}

