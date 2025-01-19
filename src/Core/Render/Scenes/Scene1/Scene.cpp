#include "Scene.hpp"
#include "Core/Log.hpp"
#include "Common.hpp"
#include "Time.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <fstream>
#include <sstream>


int SDLEventCallBack(void* userData, SDL_Event* e)
{
    MouseScroll* mouseScroll = static_cast<MouseScroll*>(userData);

    switch(e->type)
    {
    case SDL_EVENT_MOUSE_WHEEL:
    mouseScroll->m_offsetX = e->wheel.x;
    mouseScroll->m_offsetY = e->wheel.y;
    break;
    default:
    break;
    }

    return 0;
}

Scene::Scene()
: m_flashLightOn{false},
  m_lightListSize{0}
{
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // m_cameraData.setMouseX(float(m_width) / 2.0f);
    // m_cameraData.setMouseY(float(m_height) / 2.0f);

    Time time;

    SDL_AddEventWatch(SDLEventCallBack, &m_cameraData.mouseScroll());
}

Scene::~Scene()
{

}

void Scene::resize(int w, int h) 
{
    // m_width = w / 2;
    m_width = w;
    // m_height = h / 2;
    m_height = h;

    // std::cout << m_width << " , " << m_height << '\n';
    glViewport(0, 0, m_width, m_height);
}

void Scene::update(float dt)
{
    m_cameraData.setCameraUpdateSpeed(m_cameraData.camSpeed() * dt);

    float mouseMotionX, mouseMotionY;
    SDL_GetRelativeMouseState(&mouseMotionX, &mouseMotionY);

    m_cameraData.setYaw(m_cameraData.yaw() + (mouseMotionX) * 0.2f);
    m_cameraData.setPitch(m_cameraData.pitch() + -(mouseMotionY) * 0.2f);

    if(m_cameraData.pitch() > 89.9f)
    {
    m_cameraData.setPitch(89.9f);
    }
    if(m_cameraData.pitch() < -89.9f)
    {
    m_cameraData.setPitch(-89.9f);
    }

    m_cameraData.setFov(m_cameraData.fov() + m_cameraData.mouseScroll().m_offsetY);
    m_cameraData.setMouseScrollY(0);

    if(m_cameraData.fov() > 90.0f)
    {
    m_cameraData.setFov(89.0f);
    }
    if(m_cameraData.fov() < 0.0f)
    {
    m_cameraData.setFov(0.1f);
    }
}

void Scene::move(SDL_Event& e, bool& running)
{
    PlayerCamera* camera = &m_cameraData.cam();

    switch(e.type)
    {
    case SDL_EVENT_KEY_DOWN:
    switch(e.key.keysym.sym)
    {
    case SDLK_ESCAPE:
    running = false;
    break;
    case SDLK_w:
    camera->setPosition(camera->position() + (glm::normalize(camera->front()) * camera->camSpeed()));
    break;
    case SDLK_s:
    camera->setPosition(camera->position() - (glm::normalize(camera->front()) * camera->camSpeed()));
    break;
    case SDLK_a:
    camera->setPosition(camera->position() - (glm::normalize(glm::cross(camera->front(), camera->upDirection())) * camera->camSpeed()));
    break;
    case SDLK_d:
    camera->setPosition(camera->position() + (glm::normalize(glm::cross(camera->front(), camera->upDirection())) * camera->camSpeed()));
    break;
    case SDLK_8:
    // m_cam1.m_cameraPos +=
    // glm::normalize(glm::cross(triangle.m_cam.m_cameraFront, triangle.m_cam.m_cameraUp)) * cameraSpeed(triangle);
    break;
    case SDLK_9:
    // m_cam1.m_cameraPos -=
    // glm::normalize(glm::cross(triangle.m_cam.m_cameraFront, triangle.m_cam.m_cameraUp)) * cameraSpeed(triangle); break;
    case SDLK_f:
    if(m_flashLightOn)
    {
    }
    if(!m_flashLightOn)
    {
    // m_lightCube.enableLight();
    }
    break;
    case SDLK_p:
    m_cameraData.focusOnOrigin();
    break;
    case SDLK_r:
    m_cameraData.resetPosition();
    break;
    case SDLK_b:
    m_cameraData.setCameraSpeed(m_cameraData.camSpeed() + 1.0f);
    break;
    case SDLK_n:
    m_cameraData.setCameraSpeed(m_cameraData.camSpeed() - 1.0f);
    break;
    // case SDLK_SPACE:
    // triangle.m_drawLines = true;
    // break;
    default:
    break;
    }
    break;
    case SDL_EVENT_KEY_UP:
    switch(e.key.keysym.sym)
    {
    case SDLK_SPACE:
    // triangle.m_drawLines = false;
    break;
    case SDLK_f:
    {
    if(m_flashLightOn)
    {
    m_lightCollection[2].enableLight();
    m_flashLightOn = false;
    break;
    }
    if(!m_flashLightOn)
    {
    m_lightCollection[2].disableLight();
    m_flashLightOn = true;
    break;
    }
    }
    break;
    default:
    break;
    }
    break;
    default:
    break;
    }
}

void Scene::initScene()
{
    CreateData lightCubeCreateData{"Assets/Shaders/basic.vert.glsl", "Assets/Shaders/basicLight.frag.glsl"};

    for(uint32_t i = 0; i < 3; i++)
    {
    m_lightCollection.push_back(LightCube{});
    }
    for(uint32_t i = 0; i < m_lightCollection.size(); i++)
    {
    m_lightCollection[i].init(lightCubeCreateData);

    m_lightCollection[i].addUniform(UniformVariable<glm::vec3>{"cameraFrontUser", &m_cameraData.cam().front()});

    m_lightCollection[i].setScaleAmount(glm::vec3{0.5f, 0.5f, 0.5f});
    }

    m_lightListSize = static_cast<i32_t>(m_lightCollection.size());

    for(uint32_t i = 0; i < 3; i++)
    {
    m_cubeCollection.push_back(Cube{});
    }

    m_colorUser = glm::vec3{1.0f};

    m_lightCollection[2].setIsSpotlight(true);


    for(uint32_t i = 0; i < m_cubeCollection.size(); i++)
    {
    CreateData cubeCreateData{"Assets/Shaders/model.vert.glsl", "Assets/Shaders/model.frag.glsl"};
    m_cubeCollection[i].init(cubeCreateData);

    m_cubeCollection[i].addUniform(UniformVariable<glm::vec3>{"viewPositionUser", &m_cameraData.position()});
    m_cubeCollection[i].addUniform(UniformVariable<glm::vec3>{"cameraFrontUser", &m_cameraData.cam().front()});
    m_cubeCollection[i].addUniform(UniformVariable<i32_t>{"lightListSize", &m_lightListSize});

    int32_t elementCount = 8;
    int32_t beginCount = 0;
    for(uint32_t j = 0; j < m_lightCollection.size(); j++)
    {
    m_cubeCollection[i].addUniformList<0>(UniformVariable<bool>{strReplace("lightList[0].m_directional", 11, numericChar(static_cast<i32_t>(j)).c_str()).c_str(),
                                          &m_lightCollection[j].isDirectional()
                                           },
                                                (static_cast<i32_t>(j) * elementCount),
                                                "lightList[0].m_directional"
                            );
    m_cubeCollection[i].addUniformList<1>(UniformVariable<glm::vec3>{strReplace("lightList[0].m_ambient", 11, numericChar(static_cast<i32_t>(j)).c_str()).c_str(),
                                          &m_lightCollection[j].ambient()
                                                },
                                                (static_cast<i32_t>(j) * elementCount),
                                                "lightList[0].m_directional"
                     );
    m_cubeCollection[i].addUniformList<2>(UniformVariable<glm::vec3>{strReplace("lightList[0].m_diffuse", 11, numericChar(static_cast<i32_t>(j)).c_str()).c_str(),
                                          &m_lightCollection[j].diffuse()
                                                    },
                                                (static_cast<i32_t>(j) * elementCount),
                                                "lightList[0].m_directional"
                     );
    m_cubeCollection[i].addUniformList<3>(UniformVariable<glm::vec3>{strReplace("lightList[0].m_specular", 11, numericChar(static_cast<i32_t>(j)).c_str()).c_str(),
                                          &m_lightCollection[j].specular()},
                                                (static_cast<i32_t>(j) * elementCount),
                                                "lightList[0].m_directional"
                            );
    m_cubeCollection[i].addUniformList<4>(UniformVariable<glm::vec3>{strReplace("lightList[0].m_lightColor", 11, numericChar(static_cast<i32_t>(j)).c_str()).c_str(),
                                          &m_lightCollection[j].lightColor()},
                                                (static_cast<i32_t>(j) * elementCount),
                                                "lightList[0].m_directional"
                            );
    m_cubeCollection[i].addUniformList<5>(UniformVariable<glm::vec3>{strReplace("lightList[0].m_position", 11, numericChar(static_cast<i32_t>(j)).c_str()).c_str(),
                             &m_lightCollection[j].position()},
                                                (static_cast<i32_t>(j) * elementCount),
                             "lightList[0].m_directional"
                            );
    m_cubeCollection[i].addUniformList<6>(UniformVariable<glm::vec3>{strReplace("lightList[0].m_direction", 11, numericChar(static_cast<i32_t>(j)).c_str()).c_str(),
                                                   &m_lightCollection[j].direction()}, 
                                                   (static_cast<i32_t>(j) * elementCount),
                             "lightList[0].m_directional"
                     );
    m_cubeCollection[i].addUniformList<7>(UniformVariable<bool>{strReplace("lightList[0].m_isSpotlight", 11, numericChar(static_cast<i32_t>(j)).c_str()).c_str(),
                                         &m_lightCollection[j].isSpotlight()},
                                                   (static_cast<i32_t>(j) * elementCount),
                                                   "lightList[0].m_directional"
                            );
    }

    m_cubeCollection[i].addUniform(UniformVariable<float>{"phiUser", &m_lightCollection[2].phi()});
    m_cubeCollection[i].addUniform(UniformVariable<float>{"outerRadiusUser", &m_lightCollection[2].outerRadiusUser()});

    // m_cubeCollection[i].addUniform(UniformVariable<glm::vec3>{"colorUser.m_color", &m_colorUser});
    } 


    m_cubeCollection[0].setPosition(glm::vec3{0.0f, 0.0f, -1.0f});
    // m_cubeCollection[0].setScaleAmount(glm::vec3{0.75f, 0.75f, 0.75});
    m_cubeCollection[1].setPosition(glm::vec3{0.0f, 0.0f, 0.27f});
    // m_cubeCollection[1].setScaleAmount(glm::vec3{0.75f, 0.75f, 0.75});
    m_cubeCollection[2].setPosition(glm::vec3{0.0f, 0.0f, 1.0f});
    // m_cubeCollection[2].setScaleAmount(glm::vec3{0.75f, 0.75f, 0.75});


    m_lightCollection[0].setDelayLight(0.0);
    m_lightCollection[1].setDelayLight(0.2);
    // m_lightCollection[2].setDelayLight(1);
  
    // m_lightCube.setPosition(glm::vec3{1.0f, 2.0f, -0.5f});
    // m_lightCube.setDirection(glm::normalize(glm::vec3{1.0f, 2.0f, -0.5f}));
    // m_lightCube.setScaleAmount(glm::vec3{0.5f, 0.5f, 0.5f});


    m_cameraData.setFov(45.0f);
}

void Scene::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    double timeInSeconds = static_cast<double>(SDL_GetTicks()) / 1000;

    m_cameraData.updateCamera();

    // if(!m_isStopRotation)
    // {
    // m_lightCube.setPosition(glm::vec3{sin(timeInSeconds), 1.5f, cos(timeInSeconds)});
    // m_lightCube.setPosition(glm::vec3{0.0f, 1.0f, -2.0f});
    // m_lightCube.setPosition(m_cameraData.position());
    // m_lightCube.render(m_cameraData, std::pair<int32_t, int32_t>{m_width, m_height}, UniformData{});
    // }
  
    for(uint32_t i = 0; i < 2; i++)
    {
    double delayLight = m_lightCollection[i].delayLight();
    m_lightCollection[i].setPosition(glm::vec3{sin(timeInSeconds + delayLight), 1.5f, cos(timeInSeconds + delayLight)});
    m_lightCollection[i].render(m_cameraData, std::pair<int32_t, int32_t>{m_width, m_height});
    }

    m_lightCollection[2].setPosition(m_cameraData.position());
  
    for(uint32_t i = 0; i < m_cubeCollection.size(); i++)
    {
    m_cubeCollection[i].render(m_cameraData, std::pair<int32_t, int32_t>{m_width, m_height});
    }

    // m_cube.render(m_cameraData, std::pair<int32_t, int32_t>{m_width, m_height}, UniformData{});
}
