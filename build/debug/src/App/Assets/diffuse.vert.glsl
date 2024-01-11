#version 410

layout (location=0) in vec3 gVertexPos;
layout (location=1) in vec3 gVertexNorm;

layout (location=0) out vec3 gLightIntensity;

uniform vec3 uKd;
uniform vec3 uLd;
uniform vec4 uLightPosition;

uniform mat4 uModelViewMatrix;
uniform mat3 uNormalMatrix;
uniform mat4 uProjMatrix;
uniform mat4 uMvp;

void main()
{
    vec3 nVecNorm = normalize(uNormalMatrix * gVertexNorm);
     vec4 eyeCoords = uModelViewMatrix * vec4(gVertexPos, 1.0f);
      vec3 s = normalize(vec3(uLightPosition - eyeCoords));

    gLightIntensity = uKd * uLd * max(dot(s, nVecNorm), 0.0f);
     gl_Position = uMvp * vec4(gVertexPos, 1.0f);
}
