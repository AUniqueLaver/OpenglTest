#version 410

layout(location=0) in vec3 gVertexPosition;
layout(location=1) in vec3 gVertexColor;

layout(location=0) out gVColor;

out gl_PerVetex
{
     vec4 gl_Position;
     float gl_PointSize;
      float gl_ClipDistance;
};

void main()
{
     gVColor = gVertexColor;
      gl_Position = vec4(gVertexPosition, 1.0f);
}
