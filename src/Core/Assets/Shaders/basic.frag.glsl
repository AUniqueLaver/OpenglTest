#version 410 core

in vec2 outTexCoord;
in vec3 fragmentPosition;
in mat3 outNormalMatrix;
in vec3 outNormalDirection;
in mat4 outView;

out vec4 fragColor;

uniform sampler2D sampler1;
uniform vec3 viewPositionUser;
uniform vec3 lightColorUser;
uniform vec3 lightPositionUser;


void main()
{
   vec3 objectColor = vec3(0.0f, 1.0f, 0.5f);

   float ambientStrength = 0.1f;
   float ambient = ambientStrength;

   vec3 normalDirection = normalize(outNormalDirection);
   normalDirection = normalDirection * outNormalMatrix;

   vec3 lightPosition = vec3(outView * vec4(lightPositionUser, 0.0f));

   vec3 lightDirection = normalize(lightPosition - fragmentPosition);
   float diffuse = max(dot(lightDirection, normalDirection), 0) * 0.5f;

   vec3 viewDirection = normalize(-fragmentPosition);

   vec3 reflectedLightDirection = reflect(-lightDirection, normalDirection);
   
   float specular = pow(max(dot(reflectedLightDirection, viewDirection), 0.0f), 128);

   vec3 objectLight = (ambient + diffuse + specular) * lightColorUser;
   objectColor = objectLight * objectColor;

   fragColor = vec4(objectColor, 1.0f);
} 
