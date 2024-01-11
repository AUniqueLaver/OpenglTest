#version 410

const float PI = 3.14159265359;
layout(location=0) in vec3 gVColor;

layout(location=0) out vec4 gFragColor;

void main()
{
      float fac = 1 + 0.5f * cos(gl_FragCoord.x * 100 / PI);
       gFragColor = vec4(gVColor * fac, 1.0f);
       // gFragColor = vec4(gVColor, 1.0f);
}
