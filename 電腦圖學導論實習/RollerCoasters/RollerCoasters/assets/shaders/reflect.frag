#version 330 core

in vec3 vPosEye;
in vec3 vNormalEye;

out vec4 FragColor;

uniform samplerCube skybox;

void main()
{
    vec3 N = normalize(vNormalEye);

    // 從「相機 → 片段」的方向（在 eye space 裡）
    // 如果覺得反射方向怪怪的，等一下可以把這行改成 -vPosEye 試看看
    vec3 I = normalize(vPosEye);

    // 反射向量
    vec3 R = reflect(I, N);

    // 用反射方向去 sample cubemap
    FragColor = texture(skybox, R);
}
