#version 410

layout (location=0) in vec3 gLightIntensity;

layout (location=0) out vec4 gFragColor;

void main()
{
    gFragColor = vec4(gLightIntensity, 1.0f);
}
