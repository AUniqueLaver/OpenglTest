#pragma once

#include "Render/GLSLProg.hpp"
#include "Render/UniformVariable.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>

#include <iostream>


inline float convertDegreesFromRadians(float radians)
{
    return radians * 180.0f / 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679f;
}

inline float convertRadiansFromDegrees(float degrees)
{
    return degrees * 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679f / 180.0f;

}

void printVectorInformationVec3(glm::vec3 vec);

void printVectorInformationVec4(glm::vec4 vec);

void printMat3(glm::mat3 mat);

void printMat4(glm::mat4 mat);

struct Light
{
   public:
    Light()
    : m_ambient{glm::vec3{0}},
      m_diffuse{glm::vec3{0}},
      m_specular{glm::vec3{0}}
    {

    }
    ~Light()
    {

    }


    void setAmbient(glm::vec3 ambient)
    {
    m_ambient = ambient; 
    }

    void setDiffuse(glm::vec3 diffuse)
    {
    m_diffuse = diffuse; 
    }

    void setSpecular(glm::vec3 specular)
    {
    m_specular = specular; 
    }

    glm::vec3 ambient() const
    {
    return m_ambient; 
    }

    glm::vec3 diffuse() const
    {
    return m_diffuse; 
    }

    glm::vec3 specular() const
    {
    return m_specular; 
    }

   private:
    glm::vec3 m_ambient;
    glm::vec3 m_diffuse;
    glm::vec3 m_specular;
};

struct Specular
{
   public:
    Specular()
    : m_specular{glm::vec3{0}},
      m_reflectiveness{0}
    {

    }
    Specular(glm::vec3 specular, float reflectiveness)
    : m_specular{specular},
      m_reflectiveness{reflectiveness}
    {

    }
    ~Specular()
    {

    }


    void setSpecular(glm::vec3 specular)
    {
    m_specular = specular;
    }

    void setReflectiveness(float reflectiveness)
    {
    m_reflectiveness = reflectiveness;
    }

    glm::vec3 specular() const
    {
    return m_specular;
    }

    float reflectiveness() const
    { 
    return m_reflectiveness;
    }

    glm::vec3& specular()
    {
    return m_specular;
    }

    float& reflectiveness()
    { 
    return m_reflectiveness;
    }

   private:
    glm::vec3 m_specular;
    float m_reflectiveness;
};

struct Material
{
   public:
    Material()
    : m_ambient{glm::vec3{0}},
      m_diffuse{glm::vec3{0}},
      m_specular{glm::vec3{0}, 0}
    {

    }
    ~Material()
    {

    }


    void setAmbient(glm::vec3 ambient)
    {
    m_ambient = ambient; 
    }

    void setDiffuse(glm::vec3 diffuse)
    {
    m_diffuse = diffuse; 
    }

    void setSpecular(glm::vec3 specular, float reflectiveness)
    {
    m_specular.setSpecular(specular); 
    m_specular.setReflectiveness(reflectiveness); 
    }

    glm::vec3 ambient() const
    {
    return m_ambient; 
    }

    glm::vec3 diffuse() const
    {
    return m_diffuse; 
    }

    Specular specular() const
    {
    return m_specular; 
    }

    glm::vec3& ambient()
    {
    return m_ambient; 
    }

    glm::vec3& diffuse()
    {
    return m_diffuse; 
    }

    Specular& specular()
    {
    return m_specular; 
    }

   private:
    glm::vec3 m_ambient;
    glm::vec3 m_diffuse;
    Specular m_specular;
};

struct PlayerCamera
{
  public:
   PlayerCamera()
   : m_cameraPos{glm::vec3(0.0f, 0.0f, 3.0f)},
     m_cameraFront{glm::vec3(0.0f, 0.0f, -1.0f)},
     m_cameraUp{glm::vec3(0.0f, 1.0f, 0.0f)},
     m_speed{9.0f}
   {

   }
   ~PlayerCamera()
   {

   }


   void setPosition(glm::vec3 cameraPosition)
   {
   m_cameraPos = cameraPosition;
   }

   void setCameraSpeed(float camSpeed)
   {
   m_speed = camSpeed;
   }

   glm::vec3 position() const
   {
   return m_cameraPos;
   }

   glm::vec3& position()
   {
   return m_cameraPos;
   }

   glm::vec3 front() const
   {
   return m_cameraFront;
   }

   glm::vec3 upDirection() const
   {
   return m_cameraUp;
   }

   float camSpeed() const
   {
   return m_speed;
   }

   glm::vec3& front()
   {
   return m_cameraFront;
   }

  public:
   glm::vec3 m_cameraPos;
   glm::vec3 m_cameraFront;
   glm::vec3 m_cameraUp;

   float m_speed;
};

struct MouseScroll
{
    public:
     MouseScroll()
     : m_offsetX{0},
       m_offsetY{0}
     {

     }
     ~MouseScroll()
     {

     }

    public:
     float m_offsetX;
     float m_offsetY;
};

struct CameraData
{
    public:
     CameraData()
     : m_yaw{0.0f},
       m_pitch{0.0f},
       m_fov{0.0f},
       m_camSpeed{2.0f}
     {

     }
     ~CameraData()
     {

     }

     void updateCamera()
     {
     glm::vec3 cameraDirection;

     cameraDirection.x = sin(glm::radians(m_yaw))
                     * cos(glm::radians(m_pitch));
   
     cameraDirection.y = sin(glm::radians(m_pitch));

     cameraDirection.z = -cos(glm::radians(m_yaw))
                     * cos(glm::radians(m_pitch));

     m_cam.m_cameraFront = glm::normalize(cameraDirection);

     }

     void setPosition(glm::vec3 position)
     {
     m_cam.setPosition(position);
     }

     void focusOnOrigin()
     {
     // m_yaw = convertDegreesFromRadians(asin(m_cam.position().x));
     // std::cout << glm::normalize(m_cam.position()).x << '\n';
    
     // if(m_cam.position == glm::vec3{0.0f})
     // {
     // return;
     // }

     // m_cam.setPosition(glm::vec3{-1.0f, 0.0f, -1.0f});
     float positionXLength = m_cam.position().x / glm::length(m_cam.position());
     float positionYLength = m_cam.position().y / glm::length(m_cam.position());
     // m_yaw = 45.0f;
     // std::cout << positionXlength << '\n';
     // std::cout << glm::normalize(m_cam.position()).x << '\n'; 
    
     // m_yaw = convertDegreesFromRadians(asin(abs(positionXLength)));
    

     // m_cam.setPosition(glm::vec3{-1.0f, 0.0f, -1.0f});
  
     // std::cout << positionXLength << '\n';

     if((m_cam.position().x < 0) && (m_cam.position().z > 0))
     {
     m_yaw = convertDegreesFromRadians(asin(abs(positionXLength)));
     // std::cout << m_yaw << '\n';
     }
     if((m_cam.position().x < 0) && (m_cam.position().z < 0))
     {
     m_yaw = (90.0f - convertDegreesFromRadians(asin(abs(positionXLength)))) + 90.0f;
     }
     if((m_cam.position().x > 0) && (m_cam.position().z < 0))
     {
     m_yaw = convertDegreesFromRadians(asin(abs(positionXLength))) + 180.0f;
     }
     if((m_cam.position().x > 0) && (m_cam.position().z > 0))
     {
     m_yaw = (90.0f - convertDegreesFromRadians(asin(abs(positionXLength)))) + 270.0f;
     }

     if(m_cam.position().y > 0)
     {
     m_pitch = -convertDegreesFromRadians(asin(positionYLength));

     }
     if(m_cam.position().y < 0)
     {
     m_pitch = convertDegreesFromRadians(asin(abs(positionYLength)));

     }

     // std::cout << convertDegreesFromRadians(asin(abs(positionXLength))) << '\n';

     // std::cout << convertDegreesFromRadians(asin(positionXLength)) << '\n';
     }

     void resetPosition()
     {
     m_cam.setPosition(glm::vec3{0.0f, 0.0f, 1.0f});
     m_yaw = 0;
     }

     void setCameraPosition(glm::vec3 cameraPosition)
     {
     m_cam.m_cameraPos = cameraPosition;
     }

     void setCameraUpdateSpeed(float camSpeed)
     {
     m_cam.setCameraSpeed(camSpeed);
     }

     void setCameraSpeed(float camSpeed)
     {
     m_camSpeed = camSpeed;
     }

     void setYaw(float yaw)
     {
     m_yaw = yaw;
     }

     void setPitch(float pitch)
     {
     m_pitch = pitch;
     }

     void setFov(float fov)
     {
     m_fov = fov;
     }

     void setMouseLastX(float mouseLastX)
     {
     m_mouseLastX = mouseLastX;
     }

     void setMouseLastY(float mouseLastY)
     {
     m_mouseLastY = mouseLastY;
     }

     void setMouseScrollY(float mouseScrollY)
     {
     m_mouseScroll.m_offsetY = mouseScrollY;
     }

     MouseScroll mouseScroll() const
     {
     return m_mouseScroll;
     }
     MouseScroll& mouseScroll()
     {
     return m_mouseScroll;
     }

     glm::vec3 position() const
     {
     return m_cam.position();  
     }
     glm::vec3& position()
     {
     return m_cam.position();  
     }

     float yaw() const
     {
     return m_yaw;
     }

     float pitch() const
     {
     return m_pitch;
     }

     float fov() const
     {
     return m_fov;
     } 

     PlayerCamera cam() const
     {
     return m_cam;
     }

     PlayerCamera& cam()
     {
     return m_cam;
     }

     float camSpeed() const
     {
     return m_camSpeed; 
     }

    private:
     MouseScroll m_mouseScroll;

     float m_yaw;
     float m_pitch;

     float m_fov;

     PlayerCamera m_cam;
     // struct MouseData
     //  {
     float m_mouseLastX;
     float m_mouseLastY;
     // };
     float m_camSpeed;
};

class CreateData
{
    public:
     CreateData()
     {

     }
     CreateData(const char* vertexShader, const char* fragmentShader)
     : m_vertexShader{vertexShader},
       m_fragmentShader{fragmentShader}
     {

     }
     ~CreateData()
     {

     }

     const char* vertexShader() const
     {
     return m_vertexShader;
     }

     const char* fragmentShader() const
     {
     return m_fragmentShader;
     }

    private:
     const char* m_vertexShader;
     const char* m_fragmentShader;
};

class Cube
{
   public:
    Cube();
    ~Cube();

    void init(CreateData createData); 
    
    void setPosition(glm::vec3 modelPosition);
    void setScaleAmount(glm::vec3 modelScaleAmount);
    void render(CameraData& cameraData, std::pair<int32_t, int32_t> windowDimensions);

    template<typename T>
    void addUniform(UniformVariable<T>&& uniform)
    {
    i32_t loc = m_shaderProgram.findUniformLocation(uniform.name().c_str());

    m_uniforms.addUniform(uniform, loc);
    }

    template<int N, typename T>
    void addUniformList(UniformVariable<T>&& uniform, i32_t listLoc, const char* listNameBegin)
    {
    i32_t loc = m_shaderProgram.findUniformLocation(listNameBegin);

    std::cout << listLoc + N << '\n';

    m_uniforms.addUniform(uniform, loc + listLoc + N);
    }

    void addUniformBlock(const char* uniformBlockName)
    {
    m_uniformBuffers.push_back(uniformBlockName);
    }

    glm::vec3 position() const
    {
    return m_modelPosition;
    }

    glm::vec3 modelScaleAmount() const
    {
    return m_modelScale;
    }

    glm::mat4 model() const
    {
    return m_model;
    }

    Material material() const
    {
    return m_material;
    }

    glm::vec3& position()
    {
    return m_modelPosition;
    }

    GLSLProg prog() const
    {
    return m_shaderProgram;
    }

   private:
    glm::vec3 m_modelPosition;
    glm::vec3 m_modelScale;

    GLuint m_vaoHandle;

    GLuint m_texture;
    GLuint m_specularMap;

    std::vector<uint32_t> m_indicies;

    GLSLProg m_shaderProgram;
    UniformList m_uniforms;
    Vector<const char*> m_uniformBuffers;


    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_proj;

    glm::mat4 m_normalMatrix;


    Material m_material;
};
