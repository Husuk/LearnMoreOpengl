#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCord;

out vec2 TexCord;

uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;
void main()
{
    TexCord = aTexCord;
    
    gl_Position = perspective*view*model*vec4(aPos, 1.0f);
    
}