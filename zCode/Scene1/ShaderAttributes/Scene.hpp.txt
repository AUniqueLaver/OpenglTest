#pragma once

#include "Extra/SceneInterface.hpp"

#include <glad/glad.h>

#include <string>

class Scene : public SceneI
{
      public:
         Scene();
     
        virtual void update(float dt) override;
          virtual void render() override;
            virtual void initScene() override;
              virtual void resize(int w, int h) override;
      private:
    void compileShaderProg();
    void linkShader(GLint vert, GLint frag);
    void loadShaderBin(GLuint format);
     void writeShaderBin();
    void loadSpirvShader();

    std::string getShaderInfo(GLuint shader);
    std::string getProgInfo(GLuint prog);

      private:
    GLuint vaoHandle;
    GLuint programHandle;
};
