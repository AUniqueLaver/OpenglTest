#pragma once

#include "UniformVariable.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <map>
#include <forward_list>


class GLSLProg
{
   public:
    GLSLProg();
    ~GLSLProg();
    
    void compileShader(const char* fname);
    void linkShaders();
    void use();

    void deleteAttachedShaders(GLuint vert, GLuint frag);

    void addUniform(const char* name);

    void setUniforms(UniformList& uniforms);

    void setUniform(i32_t loc, float x);
    void setUniform(i32_t loc, float x, float y);
    void setUniform(i32_t loc, float x, float y, float z);
    void setUniform(i32_t loc, float x, float y, float z, float w);

    void setUniform(i32_t loc, i32_t x);
    void setUniform(i32_t loc, i32_t x, i32_t y);
    void setUniform(i32_t loc, i32_t x, i32_t y, i32_t z);
    void setUniform(i32_t loc, i32_t x, i32_t y, i32_t z, i32_t w);

    void setUniform(i32_t loc, u32_t x);
    void setUniform(i32_t loc, u32_t x, u32_t y);
    void setUniform(i32_t loc, u32_t x, u32_t y, u32_t z);
    void setUniform(i32_t loc, u32_t x, u32_t y, u32_t z, u32_t w);

    void setUniform(i32_t loc, glm::mat2 mat);
    void setUniform(i32_t loc, glm::mat3 mat);
    void setUniform(i32_t loc, glm::mat4 mat);

    void setUniform(i32_t loc, glm::vec2 vec);
    void setUniform(i32_t loc, glm::vec3 vec);
    void setUniform(i32_t loc, glm::vec4 vec);

    void setUniform(i32_t loc, int32_t count, float* floatList);
    void setUniform(i32_t loc, bool uniform);

    i32_t findUniformLocation(const char* name);
   
    void printUniformLocations();

    void queryActiveUniformName(i32_t loc,
                                i32_t bufSize,
                                i32_t* length,
                                char* uniformName);

    int32_t activeUniformsAmount();

    GLuint prog() const
    {
    return m_prog;
    }

   private:
    GLenum queryType(const char* fname);

    void checkCompileStatus(GLuint shader);
    void checkLinkStatus();

    void deleteAttachedShaders();

    // int findUniformLocation(const char* name);
    void addUniform(const char* name, int& loc);

    const char* typeToCString(GLenum type);

   private:
    GLuint m_prog;
    std::map<const char*, GLenum> m_typeMap;
    std::forward_list<UniformLoc> m_uniformLoc;
};
