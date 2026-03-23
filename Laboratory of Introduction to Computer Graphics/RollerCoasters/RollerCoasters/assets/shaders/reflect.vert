#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

out vec3 vPosEye;      // 頂點在 eye space 的位置
out vec3 vNormalEye;   // 法線在 eye space

void main()
{
    // 先把頂點從 model -> world -> eye
    vec4 worldPos = uModel * vec4(aPos, 1.0);
    vec4 viewPos  = uView * worldPos;

    gl_Position = uProjection * viewPos;

    // 傳給 fragment 用
    vPosEye = viewPos.xyz;

    // 法線用 (uView * uModel) 的逆轉置來轉到 eye space
    mat3 normalMat = mat3(transpose(inverse(uView * uModel)));
    vNormalEye = normalize(normalMat * aNormal);
}
