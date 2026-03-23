// pixel.frag
#version 330 core
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D screenTex;
uniform vec2 uResolution; // 螢幕解析度
uniform float uPixelSize; // 每個 pixel block 大小（以螢幕 pixel 為單位）

void main()
{
    // 把 0~1 的 UV 轉成螢幕座標
    vec2 uv = TexCoord * uResolution;

    // 把螢幕座標量化成格子，再除回解析度
    uv = uPixelSize * floor(uv / uPixelSize);
    uv /= uResolution;

    FragColor = texture(screenTex, uv);
}
