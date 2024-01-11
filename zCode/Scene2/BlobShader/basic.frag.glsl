#version 410 core

layout (location=0) in vec3 vTexCoord;

layout (location=0) out vec4 fragColor;

uniform gBlobSettings
{
    vec4 gInnerColor;
    vec4 gOuterColor;
    float gRadiusInner;
    float gRadiusOuter;
};

void main()
{
   float dx = vTexCoord.x - 0.5f;
    float dy = vTexCoord.y - 0.5f;
     float dist = sqrt(dx * dx + dy * dy);
      fragColor = mix(gInnerColor, gOuterColor,
                       smoothstep(gRadiusInner, gRadiusOuter, dist));
}
