// kernel.cu

// 只在這個檔案定義一次 STB 的實作
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#include <cstdio>
#include <cstdlib>

__global__ void sobelKernel(const unsigned char* in,
    unsigned char* out,
    int width, int height, int channels)
{
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;
    if (x >= width || y >= height) return;

    // 邊界像素直接設成黑色（避免取鄰居越界）
    if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
        int idx = (y * width + x) * channels;
        out[idx + 0] = 0;
        out[idx + 1] = 0;
        out[idx + 2] = 0;
        return;
    }

    auto getGray = [&](int xx, int yy) -> float {
        int idx = (yy * width + xx) * channels;
        unsigned char r = in[idx + 0];
        unsigned char g = in[idx + 1];
        unsigned char b = in[idx + 2];
        // 灰階公式
        return 0.299f * r + 0.587f * g + 0.114f * b;
    };

    // 3x3 Sobel kernel
    float g00 = getGray(x - 1, y - 1);
    float g01 = getGray(x, y - 1);
    float g02 = getGray(x + 1, y - 1);
    float g10 = getGray(x - 1, y);
    float g11 = getGray(x, y);
    float g12 = getGray(x + 1, y);
    float g20 = getGray(x - 1, y + 1);
    float g21 = getGray(x, y + 1);
    float g22 = getGray(x + 1, y + 1);

    // Sobel Gx / Gy
    float gx = -g00 - 2.0f * g10 - g20 + g02 + 2.0f * g12 + g22;
    float gy = -g00 - 2.0f * g01 - g02 + g20 + 2.0f * g21 + g22;

    // 邊緣強度（也可以用 sqrtf(gx*gx + gy*gy)）
    float mag = fabsf(gx) + fabsf(gy);

    // 正規化 & clamping
    if (mag > 255.0f) mag = 255.0f;
    if (mag < 0.0f)   mag = 0.0f;

    unsigned char edge = (unsigned char)(mag);

    int idx = (y * width + x) * channels;
    out[idx + 0] = edge;
    out[idx + 1] = edge;
    out[idx + 2] = edge;
}

int main()
{
    const char* input_path = "./images/Lenna.jpg";   // ← 改成你的圖片檔名
    const char* output_path = "./images/output.jpg";  // 輸出檔名

    int width, height, channels;

    // 讀圖（強制成 3 通道 RGB，方便處理）
    unsigned char* h_input =
        stbi_load(input_path, &width, &height, &channels, 3);

    if (!h_input) {
        printf("Failed to load image: %s\n", input_path);
        return -1;
    }
    channels = 3;
    printf("Loaded image: %d x %d, channels = %d\n", width, height, channels);

    size_t imgSize = (size_t)width * height * channels;

    // 配置 GPU 記憶體
    unsigned char* d_input = nullptr, * d_output = nullptr;
    cudaError_t err;

    err = cudaMalloc(&d_input, imgSize);
    if (err != cudaSuccess) {
        printf("cudaMalloc d_input failed: %s\n", cudaGetErrorString(err));
        stbi_image_free(h_input);
        return -1;
    }

    err = cudaMalloc(&d_output, imgSize);
    if (err != cudaSuccess) {
        printf("cudaMalloc d_output failed: %s\n", cudaGetErrorString(err));
        cudaFree(d_input);
        stbi_image_free(h_input);
        return -1;
    }

    // CPU → GPU
    err = cudaMemcpy(d_input, h_input, imgSize, cudaMemcpyHostToDevice);
    if (err != cudaSuccess) {
        printf("cudaMemcpy H2D failed: %s\n", cudaGetErrorString(err));
        cudaFree(d_input);
        cudaFree(d_output);
        stbi_image_free(h_input);
        return -1;
    }

    // 設定 kernel 執行配置
    dim3 block(16, 16);
    dim3 grid((width + block.x - 1) / block.x,
        (height + block.y - 1) / block.y);

    // 啟動 kernel（目前只是把原圖 copy 回來）
    sobelKernel << <grid, block >> > (d_input, d_output, width, height, channels);
    err = cudaGetLastError();
    if (err != cudaSuccess) {
        printf("copyKernel launch failed: %s\n", cudaGetErrorString(err));
        cudaFree(d_input);
        cudaFree(d_output);
        stbi_image_free(h_input);
        return -1;
    }

    // 等 GPU 做完
    err = cudaDeviceSynchronize();
    if (err != cudaSuccess) {
        printf("cudaDeviceSynchronize failed: %s\n", cudaGetErrorString(err));
        cudaFree(d_input);
        cudaFree(d_output);
        stbi_image_free(h_input);
        return -1;
    }

    // 準備接回 CPU 的 buffer
    unsigned char* h_output = (unsigned char*)malloc(imgSize);
    if (!h_output) {
        printf("malloc h_output failed\n");
        cudaFree(d_input);
        cudaFree(d_output);
        stbi_image_free(h_input);
        return -1;
    }

    // GPU → CPU
    err = cudaMemcpy(h_output, d_output, imgSize, cudaMemcpyDeviceToHost);
    if (err != cudaSuccess) {
        printf("cudaMemcpy D2H failed: %s\n", cudaGetErrorString(err));
        free(h_output);
        cudaFree(d_input);
        cudaFree(d_output);
        stbi_image_free(h_input);
        return -1;
    }

    // 寫出圖片（用 JPG 或 PNG 都可以）
    int ok = stbi_write_jpg(output_path, width, height, channels, h_output, 95);
    if (!ok) {
        printf("Failed to write image: %s\n", output_path);
    }
    else {
        printf("Saved image to %s\n", output_path);
    }

    // 清理資源
    free(h_output);
    cudaFree(d_input);
    cudaFree(d_output);
    stbi_image_free(h_input);

    return 0;
}
