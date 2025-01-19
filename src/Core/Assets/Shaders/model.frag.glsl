#version 410 core

in vec2 outTexCoord;
in vec3 fragmentPosition;
in vec3 outNormalDirection;

out vec4 fragColor;

struct MaterialLight
{
    vec3 m_ambient;
    vec3 m_diffuse;
    vec3 m_specular;
};

struct Light
{
    bool m_directional; 

    vec3 m_ambient;
    vec3 m_diffuse;
    vec3 m_specular;

    vec3 m_lightColor;
    vec3 m_lightPosition;
    vec3 m_lightDirection;

    bool m_isSpotlight;
};

struct A
{
   vec3 m_num;
   vec3 m_num1;
};

uniform A[2] numUser;

struct Specular
{
    vec3 m_specular;
    float m_reflectiveness;
};

struct Material
{
    vec3 m_ambient; 
    vec3 m_diffuse; 
    Specular m_specular; 
};

uniform mat3 normalMatrixUser;

uniform sampler2D sampler1;
uniform sampler2D sampler2;
uniform float phiUser;
uniform float outerRadiusUser;
uniform vec3 cameraFrontUser;
uniform vec3 viewPositionUser;
uniform Material material;

uniform Light[64] lightList;
uniform int lightListSize;

vec3 ambientValues(int index,
                   vec3 textureAmbient
                   )
{
   return lightList[index].m_ambient * textureAmbient;
}

vec3 diffuseValues(int index,
                   vec3 lightDirection,
                   vec3 fragmentPosition,
                   vec3 normalDirection,
                   vec3 textureDiffuse)
{
   vec3 diffuse = max(dot(lightDirection, normalDirection), 0) * material.m_diffuse * lightList[index].m_diffuse;

   return diffuse * textureDiffuse;
}

vec3 specularValues(int index,
                    vec3 lightDirection,
                    vec3 viewPosition,
                    vec3 fragmentPosition,
                    vec3 normalDirection,
                    vec3 textureSpecular
                    )
{
   vec3 viewDirection = normalize(viewPosition - fragmentPosition);

   vec3 reflectedLightDirection = reflect(-lightDirection, normalDirection);

   vec3 specular = pow(max(dot(reflectedLightDirection, viewDirection), 0.0f), material.m_specular.m_reflectiveness) * material.m_specular.m_specular * lightList[index].m_specular;

   return specular * textureSpecular;
}


void main()
{
   vec3 ambient = vec3(0.0f);
   vec3 specular = vec3(0.0f);
   vec3 diffuse = vec3(0.0f);


   vec3 objectLight = vec3(1.0f, 1.0f, 1.0f);

   vec3 previousLight = vec3(0.0f, 0.0f, 0.0f);

   // Have seperate directional light
   for(int i = 0; i < lightListSize; i++)
   {
   vec3 normalDirection = normalize(outNormalDirection);
   // normalDirection = normalDirection * normalMatrixUser;
   
   vec3 lightDirection = vec3(0.0f, 0.0f, 0.0f);
   if(lightList[i].m_directional)
   {
   lightDirection = lightList[i].m_lightDirection;
   }
   if(!lightList[i].m_directional)
   {
   lightDirection = normalize(lightList[i].m_lightPosition - fragmentPosition);
   }
   // if(lightList[i].m_isSpotlight)
   // {
   //
   // }

   float lightIntensity = 1.0f;
   if(!lightList[i].m_directional)
   {
   float lightDistance = length(fragmentPosition - lightList[i].m_lightPosition);

   float kq = 0.1f;
   float kl = 0.252f;
   float kc = 1.0f;

   lightIntensity = pow((kq * pow(lightDistance, 2) + kl * lightDistance + kc), -1);
   }

   ambient = ambientValues(i,
                           vec3(texture(sampler1, outTexCoord))
                          );
   diffuse = diffuseValues(i,
                           lightDirection,
                           fragmentPosition,
                           normalDirection,
                           vec3(texture(sampler1, outTexCoord))
                          );
   specular = specularValues(i,
                             lightDirection,
                             viewPositionUser,
                             fragmentPosition,
                             normalDirection,
                             vec3(texture(sampler2, outTexCoord)) 
                             );

   if(lightList[i].m_isSpotlight)
   {
   float phi = phiUser;
   float theta = acos(dot(-lightDirection, cameraFrontUser));
   vec3 spotlight = vec3(1.0f, 1.0f, 1.0f);

   float epsilon = outerRadiusUser - phiUser;
   float spotlightStrength = (theta - outerRadiusUser) / epsilon;

   spotlight = spotlight * max(-spotlightStrength, 0.0001f);

   ambient = ambient * spotlight.x;
   diffuse = diffuse * spotlight.y;
   specular = specular * spotlight.z;
   }

   vec3 lightElements = (ambient + diffuse + specular) * lightIntensity;

   if(((lightElements.x + lightElements.y + lightElements.z) > (previousLight.x + previousLight.y + previousLight.z)))
   {
   objectLight = lightElements;
   previousLight = objectLight;
   }
   }


   // objectLight = vec3(1.0f, 1.0f, 1.0f);
   
   vec3 objectColor = objectLight;

   fragColor = vec4(objectColor, 1.0f);
} 
