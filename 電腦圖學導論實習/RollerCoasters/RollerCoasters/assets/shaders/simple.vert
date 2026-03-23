#version 330 core

layout(location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 uProjection;
uniform mat4 uView;

void main()
{
    TexCoords = aPos;

    // 移除平移，讓 skybox 不跟著相機平移
    mat4 view = mat4(mat3(uView));

    vec4 pos = uProjection * view * vec4(aPos, 1.0);

    gl_Position = pos.xyww;  // w 修正，讓 depth = 1.0
}
