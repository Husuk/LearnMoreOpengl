#version 330 core

out vec4 FragColor;
in vec3 fColor;
in vec2 TexCord;
uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;
uniform float gamma;
uniform float blue;

void main()
{
    FragColor = mix(texture(ourTexture, TexCord) , texture(ourTexture2,TexCord),0.5f);
} 