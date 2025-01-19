#version 410 core

in vec2 outTexCoord;

out vec4 fragColor;

uniform sampler2D sampler1;
uniform vec3 lightColorUser;


void main()
{
   fragColor = vec4(lightColorUser, 1.0f);
   // fragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
} 
