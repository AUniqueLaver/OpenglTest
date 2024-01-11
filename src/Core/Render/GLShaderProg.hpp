#pragma once

#include "Common.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>

enum GLSLTypes
{
    VERTEX = GL_VERTEX_SHADER,
    FRAGMENT = GL_FRAGMENT_SHADER,
    TESS_CONTROL = GL_TESS_CONTROL_SHADER,
    TESS_EVAL = GL_TESS_EVALUATION_SHADER,
    GEOMETRY = GL_GEOMETRY_SHADER,
    COMPUTE = GL_COMPUTE_SHADER
};

class ShaderProgOpenGL
{
     public:
        ShaderProgOpenGL();
         ~ShaderProgOpenGL();
           
       void compileShader(const char* fname);
        void compileShader(const char* fname, GLSLTypes type);
     void compileShader(const char* fname,
                        GLSLTypes type,
                        const std::string& sCode);
            void linkShaders();

              void use();

         void deleteDetachShaders();

            void findUniformLocations();

             void printActiveAttribs();
              void printActiveUniforms();
               void printUniformBlocks();

    std::string getExtension(const char* fname);

        void setUniform(const char* name, float x, float y, float z);
        void setUniform(const char* name, const glm::vec2& v);
        void setUniform(const char* name, const glm::vec3& v);
        void setUniform(const char* name, const glm::vec4& v);
        void setUniform(const char* name, const glm::mat2& m);
        void setUniform(const char* name, const glm::mat3& m);
        void setUniform(const char* name, const glm::mat4& m);
        void setUniform(const char* name, const GLuint& val);
        void setUniform(const char* name, const int& val);
        void setUniform(const char* name, const float& val);
        void setUniform(const char* name, const bool&  val);

         std::string getTypeString(GLenum type);
     private:
        std::map<std::string, GLSLTypes> getGlslExtensions(); 
         GLint getUniformLocation(const char* name); 
     private:

           GLuint m_programHandle;

         bool m_linked;
            std::map<std::string, GLint> m_uLocations;
};
