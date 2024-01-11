#pragma once

#include "Extra/SceneInterface.hpp"
#include "Render/GLShaderProg.hpp"

#include <glad/glad.h>

#include <string>

class Scene : public IScene
{
      public:
         Scene();
     
        virtual void update(float dt) override;
          virtual void render() override;
            virtual void initScene() override;
              virtual void resize(int w, int h) override;
      private:

      private:
     float m_angle;
       GLuint m_vaoHandle;
          ShaderProgOpenGL m_prog;
        GLuint ebo;
};
