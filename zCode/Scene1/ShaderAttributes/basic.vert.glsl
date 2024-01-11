#version 410 core

layout (location=0) in vec3 vertexPosition;
layout (location=1) in vec3 vertexColor;

layout (location=0) out vec3 vColor;

uniform mat4 gRotationMatrix;

void main()
{
     vColor = vertexColor;
     gl_Position = gRotationMatrix * vec4(vertexPosition, 1.0);
}
