#include "Scene.hpp"
#include "Core/Log.hpp"
#include "Common.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <fstream>
#include <sstream>

Scene::Scene()
 : m_angle{0.0f}
{   

}
void Scene::update(float dt) 
{
   if(isAnimating())
     m_angle += dt;
   if(m_angle >= 360.0f)
     m_angle = 0.0f;

}
void Scene::render() 
{
                glClear(GL_COLOR_BUFFER_BIT);

              glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f),
                                                     m_angle,
                                                     glm::vec3(0.0f,
                                                               0.0f,
                                                               1.0f));

                  glBindVertexArray(m_vaoHandle);

                  m_prog.setUniform("gRotation", rotationMatrix);
                 
                      // glDrawArrays(GL_TRIANGLES, 0, 3);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
                    glBindVertexArray(0);
}
void Scene::initScene() 
{
      m_prog.compileShader("Assets/basic.vert.glsl");
        m_prog.compileShader("Assets/basic.frag.glsl");
         m_prog.linkShaders();
          m_prog.use();

       float posData[] = 
        {
             // -0.5f, -0.5f, 0.0f,    //Bottom left
             //  0.5f, -0.5f, 0.0f,    //Bottom right
             //  0.0f,  0.5f, 0.0f     //Top
             -0.5f, -0.5f, 0.0f,    //Bottom left
              0.5f, -0.5f, 0.0f,    //Bottom right
             -0.5f,  0.5f, 0.0f,    //Top left
              0.5f,  0.5f, 0.0f     //Top right
        };
   
       float colData[] =
        {
             1.0f, 0.0f, 0.0f,
             0.0f, 1.0f, 0.0f,
             0.0f, 0.0f, 1.0f
        };

        unsigned int indices[] =
         {
              0, 1, 2,
              1, 2, 3
         };

    GLuint vboHandles[2];
      glGenBuffers(2, vboHandles);
       GLuint posBufferHandle = vboHandles[0];
        GLuint colBufferHandle = vboHandles[1];
   
    // glBindBuffer(GL_ARRAY_BUFFER, posBufferHandle);
    //   glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), posData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, posBufferHandle);
      glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), posData, GL_STATIC_DRAW);

        glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
                   indices,
                   GL_STATIC_DRAW);

       glBindBuffer(GL_ARRAY_BUFFER, colBufferHandle);
        glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colData, GL_STATIC_DRAW);

       glGenVertexArrays(1, &m_vaoHandle);
        glBindVertexArray(m_vaoHandle);

              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

      glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
     
     glBindBuffer(GL_ARRAY_BUFFER, posBufferHandle);
       glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
      
    glBindBuffer(GL_ARRAY_BUFFER, colBufferHandle);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
   
     glBindVertexArray(0);
}

void Scene::resize(int w, int h) 
{
     width = w;
     height = h;
      glViewport(0, 0, w, h);
}
