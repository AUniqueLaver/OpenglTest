#version 410 core

layout (location=0) in vec3 vertPos;
layout (location=1) in vec3 normalDirection;
layout (location=2) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec2 outTexCoord;
out vec3 fragmentPosition;
out vec3 outNormalDirection;
out vec3 outView;

void main()
{
     gl_Position = proj * view * model * vec4(vertPos, 1.0f);
     // gl_Position = proj * view * model * vec4(vertPos, 1.0f);
     fragmentPosition = vec3(model * vec4(vertPos, 1.0f));
     outTexCoord = texCoord;
     outNormalDirection = normalDirection;
     //0.683          0.757       0.5664
}
