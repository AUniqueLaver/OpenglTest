#version 410

layout(location=0) in vec3 gVertexPosition;
layout(location=1) in vec3 gVertexColor;

layout(location=0) out vec3 gVColor;

uniform mat4 gRotation;

void main()
{
     gVColor = gVertexColor;
      gl_Position = gRotation * vec4(gVertexPosition, 1.0f);
}
