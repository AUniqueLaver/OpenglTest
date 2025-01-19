#version 410

layout(location=0) in vec3 gVertexPosition;
layout(location=1) in vec2 gVertexTex;

layout(location=0) out vec2 gvTexCoord;

uniform mat4 uProj;
uniform mat4 uView;
uniform mat4 uModel;

void main()
{
     gvTexCoord = gVertexTex;
      gl_Position = uProj * uView * uModel * vec4(gVertexPosition, 1.0f);
}
