#version 330 core

in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D screenTex;

void main()
{
    vec3 col = texture(screenTex, TexCoord).rgb;

    // ========= 1) Sobel 邊緣偵測 =========
    vec2 texel = 1.0 / vec2(textureSize(screenTex, 0));

    vec3 c00 = texture(screenTex, TexCoord + texel * vec2(-1.0, -1.0)).rgb;
    vec3 c10 = texture(screenTex, TexCoord + texel * vec2( 0.0, -1.0)).rgb;
    vec3 c20 = texture(screenTex, TexCoord + texel * vec2( 1.0, -1.0)).rgb;

    vec3 c01 = texture(screenTex, TexCoord + texel * vec2(-1.0,  0.0)).rgb;
    vec3 c11 = col;
    vec3 c21 = texture(screenTex, TexCoord + texel * vec2( 1.0,  0.0)).rgb;

    vec3 c02 = texture(screenTex, TexCoord + texel * vec2(-1.0,  1.0)).rgb;
    vec3 c12 = texture(screenTex, TexCoord + texel * vec2( 0.0,  1.0)).rgb;
    vec3 c22 = texture(screenTex, TexCoord + texel * vec2( 1.0,  1.0)).rgb;

    float g00 = dot(c00, vec3(0.299, 0.587, 0.114));
    float g10 = dot(c10, vec3(0.299, 0.587, 0.114));
    float g20 = dot(c20, vec3(0.299, 0.587, 0.114));
    float g01 = dot(c01, vec3(0.299, 0.587, 0.114));
    float g11 = dot(c11, vec3(0.299, 0.587, 0.114));
    float g21 = dot(c21, vec3(0.299, 0.587, 0.114));
    float g02 = dot(c02, vec3(0.299, 0.587, 0.114));
    float g12 = dot(c12, vec3(0.299, 0.587, 0.114));
    float g22 = dot(c22, vec3(0.299, 0.587, 0.114));

    float Gx = -g00 - 2.0 * g01 - g02 + g20 + 2.0 * g21 + g22;
    float Gy = -g00 - 2.0 * g10 - g20 + g02 + 2.0 * g12 + g22;

    float edge = length(vec2(Gx, Gy));

    float edgeStrength  = 0.5;   // 邊緣強度
    float edgeThreshold = 0.25;  // 邊緣閾值（小一點邊更多）

    edge *= edgeStrength;
    bool isEdge = edge > edgeThreshold;

    // ========= 2) 只量化亮度，保留原本顏色方向 =========
    float levels = 6.0; // 4~8 之間試試
    // 原始亮度
    float I  = dot(col, vec3(0.299, 0.587, 0.114));
    // 亮度做階層
    float Iq = floor(I * levels) / levels;

    // 保留原先的色相，用單位化的色向量乘上量化亮度
    vec3 dir = normalize(col + 1e-4); // 避免除以 0
    vec3 toonCol = dir * Iq;

    // 避免太灰：跟原色混一點
    float keepOriginal = 0.3; // 越大越接近原色
    toonCol = mix(toonCol, col, keepOriginal);

    // ========= 3) 邊緣畫成黑色 =========
    if (isEdge) {
        toonCol = vec3(0.0);
    }

    FragColor = vec4(toonCol, 1.0);
}
