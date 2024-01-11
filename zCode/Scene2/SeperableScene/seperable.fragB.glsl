#version 410

layout(location=0) in vec3 gVColor;

layout(location=0)

void main()
{
      float fac = 1 + 0.5f * cos(gl_FragCoord.x * 100 / PI);
       gFragColor = vec4(gVColor * fac, 1.0f);
}
