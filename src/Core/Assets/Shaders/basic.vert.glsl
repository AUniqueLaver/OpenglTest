#version 410 core

layout (location=0) in vec3 vertPos;
layout (location=1) in vec3 normalDirection;
layout (location=2) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec2 outTexCoord;
out vec3 fragmentPosition;
out mat3 outNormalMatrix;
out vec3 outNormalDirection;
out mat4 outView;

void main()
{
     gl_Position = proj * view * model * vec4(vertPos, 1.0f);
     fragmentPosition = vec3(view * model * vec4(vertPos, 1.0f));
     outNormalMatrix = mat3(view) * inverse(transpose(mat3(model)));
     outView = view * model;
     outNormalDirection = vec3(view * model * vec4(normalDirection, 0.0f));
     outTexCoord = texCoord;
}
