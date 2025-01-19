#pragma once

#include "NumberCharConversion.hpp"
#include "Extra/SceneInterface.hpp"
#include "Render/GLSLProg.hpp"

// #include "Square.hpp"
// #include "Triangle.hpp"
#include "Cube.hpp"

#include <glad/glad.h>
#include <SDL3/SDL.h>

#include <string>


inline std::string strReplace(const char* lightName, const uint32_t indexReplace, const char* replaceChar)
{
    std::string buffer;
    std::string buffer1;

    buffer.reserve(strlen(lightName));
    buffer1.reserve(strlen(lightName));

    buffer = lightName;

    buffer1 += replaceChar;
    buffer1 += (lightName + indexReplace);

    uint32_t bufferIndex = 0;
    for(uint32_t i = indexReplace - 1;i < strlen(lightName); i++)
    {
    buffer[i] = buffer1[bufferIndex];
    bufferIndex++;
    }

    return buffer;
}

class LightCube
{
   public:
    LightCube()
    : m_isEnabled{true},
      m_isDirectional{false},
      m_direction{glm::vec3{0.0f}},
      m_isSpotlight{false},
      m_ambient{glm::vec3{1.0f}},
      m_diffuse{glm::vec3{1.0f}},
      m_specular{glm::vec3{1.0f}},
      m_phi{convertRadiansFromDegrees(15.0f)},
      m_outerRadiusUser{convertRadiansFromDegrees(20.0f)},
      m_lightColor{glm::vec3{1.0f}},
      m_delayLight{0.0f}
    {
    m_cube.setPosition(glm::vec3{0.0f});

    m_ambient = glm::vec3{0.1f};
    m_diffuse = glm::vec3{0.8f};
    m_specular = glm::vec3{1.0f};

    }
    ~LightCube()
    {

    }


    void init(CreateData cubeData)
    {
    m_cube.init(cubeData);

    // m_cube.addUniform(createListUniform<glm::vec3>("lightListUser[0].m_position",
    //                                                &m_cube.position(),
    //                                               )
    //                  );
      
    // bool m_directional; 
    //
    // vec3 m_ambient;
    // vec3 m_diffuse;
    // vec3 m_specular;
    //
    // vec3 m_lightColor;
    // vec3 m_lightPosition;
    // vec3 m_lightDirection;
    //
    // bool m_isSpotlight;


    // [ Defining list uniforms is unclear and should 
    //   change the naming is done and location found
    //   when adding ]
      
    // m_cube.addUniformList<6>(UniformVariable<float>{"lightList[0].m_position",
    //                                            &m_phi},
    //                                            index
    //                  );
    // m_cube.addUniformList<7>(UniformVariable<float>{"lightList[0].m_position",
    //                                              &m_outerRadiusUser},
    //                                              index
    //                         );

    m_cube.addUniform(UniformVariable<glm::vec3>{"lightColorUser",
                                                 &m_lightColor
                                                }
                     );
    }

    template<typename T>
    void addUniform(UniformVariable<T>&& uniform)
    {
    m_cube.addUniform(std::forward<UniformVariable<T>>(uniform));
    }

    void render(CameraData& cameraData, std::pair<int32_t, int32_t> windowDimensions)
    {
    m_cube.render(cameraData, windowDimensions);
    }

    void setScaleAmount(glm::vec3 scaleAmount)
    {
    m_cube.setScaleAmount(scaleAmount);
    }

    void setPosition(glm::vec3 position)
    {
    m_cube.setPosition(position);
    }

    void setDirection(glm::vec3 direction)
    {
    m_isDirectional = true;
    m_direction = direction;
    }

    void setIsSpotlight(bool isSpotlight)
    {
    m_isSpotlight = isSpotlight;
    }

    void disableLight()
    {
    m_ambient = glm::vec3{0.0f};
    m_diffuse = glm::vec3{0.0f};
    m_specular = glm::vec3{0.0f};
    }

    void enableLight()
    {
    m_ambient = glm::vec3{0.1f};
    m_diffuse = glm::vec3{0.8f};
    m_specular = glm::vec3{1.0f};
    }

    void setDelayLight(double delayLight)
    {
    m_delayLight = delayLight;
    }

    bool isEnabled() const
    {
    return m_isEnabled;
    }

    bool isDirectional() const
    {
    return m_isDirectional;
    }

    glm::vec3 direction() const
    {
    return m_direction;
    }

    bool isSpotlight() const
    {
    return m_isSpotlight;
    }

    glm::vec3 modelScaleAmount() const
    {
    return m_cube.modelScaleAmount();
    }

    glm::vec3 position() const
    {
    return m_cube.position();
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

    double delayLight() const
    {
    return m_delayLight;
    }

    glm::vec3& position()
    {
    return m_cube.position();
    }

    bool& isDirectional()
    {
    return m_isDirectional;
    }

    Vec3& direction()
    {
    return m_direction;
    }

    bool& isSpotlight()
    {
    return m_isSpotlight;
    }

    Vec3& ambient()
    {
    return m_ambient;
    }

    Vec3& diffuse()
    {
    return m_diffuse;
    }

    Vec3& specular()
    {
    return m_specular;
    }

    float& phi()
    {
    return m_phi;
    }

    float& outerRadiusUser()
    {
    return m_outerRadiusUser;
    }

    Vec3& lightColor()
    {
    return m_lightColor;
    }

   private:
    template<typename T>
    UniformVariable<T> createListUniform(const char* listName,
                                         i32_t index,
                                         const char* uniformName,
                                         T* t
                                        )

    {
    u64_t unifromNameLength = strlen(listName);
    std::unique_ptr<char[]> lightListUniformBuffer = std::make_unique<char[]>(unifromNameLength + 4 + strlen(uniformName));


    strcpy(lightListUniformBuffer.get(), listName);

    strcat(lightListUniformBuffer.get(), "[");
    strcat(lightListUniformBuffer.get(), numericChar(index).c_str());
    strcat(lightListUniformBuffer.get(), "].");

    strcat(lightListUniformBuffer.get(), uniformName);

    std::cout << lightListUniformBuffer.get() << '\n';

    return UniformVariable<T>{lightListUniformBuffer.get(), t};
    }

   private:
    bool m_isEnabled;

    bool m_isDirectional;
    glm::vec3 m_direction;

    bool m_isSpotlight;

    glm::vec3 m_ambient;
    glm::vec3 m_diffuse;
    glm::vec3 m_specular;

    float m_phi;
    float m_outerRadiusUser;

    Vec3 m_lightColor;

    double m_delayLight;
    
    UniformList m_uniformList;

    Cube m_cube;
};

class Scene : public IScene
{
      public:
       Scene();
       ~Scene();
    
       virtual void update(float dt) override;
       virtual void initScene() override;
       virtual void render() override;
       virtual void resize(int w, int h) override;

       void move(SDL_Event& e, bool& running) override;

       void createObj();

      private:

      private:
       bool m_flashLightOn;

       std::vector<Cube> m_cubeCollection;

       LightCube m_lightCube;

       std::vector<LightCube> m_lightCollection;
       int32_t m_lightListSize;

       glm::vec3 m_colorUser;

       CameraData m_cameraData;
};
