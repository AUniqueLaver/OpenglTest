#version 410 core

layout (location=0) in vec3 vertPos;
layout (location=1) in vec2 texCoord;

uniform mat4 transform;

out vec2 outTexCoord;

void main()
{
     gl_Position = transform * vec4(vertPos, 1.0f);
     outTexCoord = texCoord;
}
