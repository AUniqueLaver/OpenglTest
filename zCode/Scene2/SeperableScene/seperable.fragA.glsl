#version 410

layout(location=0) in vec3 gVColor;

layout(location=0) out vec4 gFragColor;

void main()
{
     gFragColor = vec4(gVColor, 1.0f);
}
