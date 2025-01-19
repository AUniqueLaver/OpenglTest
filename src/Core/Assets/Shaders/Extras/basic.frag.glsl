#version 410

layout(location=0) in vec2 gvTexCoord;

layout(location=0) out vec4 gFragColor;

uniform sampler2D sampler1;
uniform sampler2D sampler2;

void main()
{
 gFragColor = mix(texture(sampler1, vec2(gvTexCoord)),
                                       texture(sampler2, gvTexCoord),
                                       0.2);
}
