#include "TorusScene.hpp"
#include "Core/Log.hpp"
#include "Common.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <fstream>
#include <sstream>

TorusScene::TorusScene()
 : m_angle{0.0f}
{   
      // torus.initTorus(20,4.0f,8,30);
        torus.initTorus(0.7f,0.3f,30,30);
}
void TorusScene::update(float dt) 
{
   if(isAnimating())
     m_angle += dt;
   if(m_angle >= 360.0f)
     m_angle = 0.0f;

}
void TorusScene::render() 
{
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                  setMatrices();
                    torus.render();
}
void TorusScene::initScene() 
{
      m_prog.compileShader("Assets/diffuse.vert.glsl");
        m_prog.compileShader("Assets/diffuse.frag.glsl");
         m_prog.linkShaders();
          m_prog.use();

    glEnable(GL_DEPTH_TEST);

     m_model = glm::mat4(1.0f);
      m_model = glm::rotate(m_model, glm::radians(-35.0f), glm::vec3(1.0f,
                                                                0.0f,
                                                                0.0f));
      m_model = glm::rotate(m_model, glm::radians(35.0f), glm::vec3(0.0f,
                                                                1.0f,
                                                                0.0f));

        m_view = glm::lookAt(glm::vec3(0.0f,0.0f,2.0f),
                           glm::vec3(0.0f,0.0f,0.0f),
                           glm::vec3(0.0f,1.0f,0.0f));

         m_proj = glm::mat4(1.0f);
            
           m_prog.setUniform("uKd", 0.9f, 0.5f, 0.3f);
            m_prog.setUniform("uLd", 1.0f, 1.0f, 1.0f);
             m_prog.setUniform("uLightPosition", m_view * glm::vec4(5.0f,
                                                                 5.0f,
                                                                 2.0f,
                                                                 1.0f));
}

void TorusScene::setMatrices()
{
    glm::mat4 mv = m_view * m_model;
      m_prog.setUniform("uModelViewMatrix", mv);
       m_prog.setUniform("uNormalMatrix", 
                         glm::mat3(glm::vec3(mv[0]),
                                   glm::vec3(mv[1]),
                                   glm::vec3(mv[2])));
        m_prog.setUniform("uMvp", m_proj * mv);
}

void TorusScene::resize(int w, int h) 
{
     width = w;
     height = h;
      glViewport(0, 0, w, h);
        m_proj = glm::perspective(glm::radians(70.0f),
                                      static_cast<float>(w/h),
                                      0.3f,
                                      100.0f);
}
