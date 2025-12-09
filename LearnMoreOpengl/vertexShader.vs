#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 ourColor;
layout (location = 2) in vec2 aTexCord;
out vec3 fColor;
out vec2 TexCord;

uniform mat4 transform;
void main()
{
    TexCord = aTexCord;
    fColor = ourColor;
    gl_Position = transform*vec4(aPos, 1.0f);
    
}