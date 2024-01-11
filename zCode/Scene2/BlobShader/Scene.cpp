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
     m_angle += 0.1f;
   if(m_angle >= 360.0f)
     m_angle = 0.0f;

}
void Scene::render() 
{
                glClear(GL_COLOR_BUFFER_BIT);

                  glBindVertexArray(vaoHandle);
                   glDrawArrays(GL_TRIANGLES, 0, 6);
                    glBindVertexArray(0);
}
void Scene::initScene() 
{
     compileShaderProg();

        initUniformBufferBlocks();

       float posData[] = 
        {
             -0.8f, -0.8f, 0.0f,
              0.8f, -0.8f, 0.0f,
              0.8f,  0.8f, 0.0f,
             -0.8f, -0.8f, 0.0f,
              0.8f,  0.8f, 0.0f,
             -0.8f,  0.8f, 0.0f
        };
   
       float colData[] =
        {
             0.0f, 0.0f, 
             1.0f, 0.0f,
             1.0f, 1.0f, 
             0.0f, 0.0f, 
             1.0f, 1.0f,
             0.0f, 1.0f
        };

    GLuint vboHandles[2];
      glGenBuffers(2, vboHandles);
       GLuint posBufferHandle = vboHandles[0];
        GLuint colBufferHandle = vboHandles[1];
   
    glBindBuffer(GL_ARRAY_BUFFER, posBufferHandle);
      glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), posData, GL_STATIC_DRAW);

       glBindBuffer(GL_ARRAY_BUFFER, colBufferHandle);
        glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), colData, GL_STATIC_DRAW);

       glGenVertexArrays(1, &vaoHandle);
        glBindVertexArray(vaoHandle);

      glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
     
     glBindBuffer(GL_ARRAY_BUFFER, posBufferHandle);
       glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
      
    glBindBuffer(GL_ARRAY_BUFFER, colBufferHandle);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

       glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
         glBindVertexArray(0);
}
void Scene::initUniformBufferBlocks()
{
   GLint blockIndex = glGetUniformBlockIndex(programHandle,
                                             "gBlobSettings");
   
    GLint blockSize;
     glGetActiveUniformBlockiv(programHandle, 
                               blockIndex,
                               GL_UNIFORM_BLOCK_DATA_SIZE, 
                               &blockSize);

      GLubyte* blockBuffer;
       blockBuffer = (GLubyte*)malloc(sizeof(GLubyte*) * 4);

      const GLchar* names[] = {"gInnerColor",
                               "gOuterColor",
                               "gRadiusInner",
                               "gRadiusOuter"};
      
     GLuint indices[4];
      glGetUniformIndices(programHandle, 4, names, indices);
   
      GLint offset[4];
       glGetActiveUniformsiv(programHandle,
                            4,
                            indices,
                            GL_UNIFORM_OFFSET,
                            offset);

       GLfloat innerColor[] = {1.0f, 0.0f, 0.0f, 1.0f};
        GLfloat outerColor[] = {0.0f, 0.0f, 0.0f, 0.0f};
         GLfloat innerRad = 0.25f;
          GLfloat outerRad = 0.45f;

      memcpy(blockBuffer + offset[0], innerColor, sizeof(GLfloat) * 4);
       memcpy(blockBuffer + offset[1], outerColor, sizeof(GLfloat) * 4);
        memcpy(blockBuffer + offset[2], &innerRad, sizeof(GLfloat));
         memcpy(blockBuffer + offset[3], &outerRad, sizeof(GLfloat));

       GLuint uboHandle;
        glGenBuffers(1, &uboHandle);
        
       glBindBuffer(GL_UNIFORM_BUFFER, uboHandle);
        glBufferData(GL_UNIFORM_BUFFER,
                     blockSize,
                     blockBuffer,
                     GL_DYNAMIC_DRAW);

     glBindBufferBase(GL_UNIFORM_BUFFER, 1, uboHandle);

       glUniformBlockBinding(programHandle, blockIndex, 1);
}

void Scene::resize(int w, int h) 
{
     width = w;
     height = h;
      glViewport(0, 0, w, h);
}

void Scene::compileShaderProg()
{
    std::ifstream vertFile("Assets/basic.vert.glsl");
       if(!vertFile)
         {
             LOG_FATAL("Vertex shader file not found!");
         }

   std::stringstream vertCode;
     vertCode << vertFile.rdbuf();
        vertFile.close();
          std::string vertCodeStr(vertCode.str());

      GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
        if(vertShader == 0)
         {
            LOG_FATAL("Error creating vertex shader");
         }

  const GLchar* vertCodeArray[] = { vertCodeStr.c_str() };
      glShaderSource(vertShader, 1, vertCodeArray, NULL);
        glCompileShader(vertShader);

      GLint vertResult;
        glGetShaderiv(vertShader, GL_COMPILE_STATUS, &vertResult);
         if(vertResult == GL_FALSE)
          {
              LOG_FATAL("Error compiling vertex shader " + getShaderInfo(vertShader));
          }

      std::ifstream fragFile("Assets/basic.frag.glsl");
       if(!fragFile)
         {
             LOG_FATAL("Fragment shader file not found!");
         }
         
         std::stringstream fragCode;
          fragCode << fragFile.rdbuf();
           fragFile.close();
            std::string fragCodeStr(fragCode.str()); 

        GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
        if(vertShader == 0)
         {
             LOG_FATAL("Error creating fragment shader");
         }

    const GLchar* fragCodeArray[] { fragCodeStr.c_str() };
     glShaderSource(fragShader, 1, fragCodeArray, NULL);
      glCompileShader(fragShader);
   
    GLint fragResult;
     glGetShaderiv(fragShader, GL_COMPILE_STATUS, &fragResult);
         if(fragResult == GL_FALSE)
          {
             LOG_FATAL("Error compiling fragment shader " + getProgInfo(fragShader));
          }

     linkShader(vertShader, fragShader);
}

void Scene::linkShader(GLint vert, GLint frag)
{
      programHandle = glCreateProgram();
       if(!programHandle)
        {
          LOG_FATAL("Error creating program handle");
        }

       glAttachShader(programHandle, vert);
        glAttachShader(programHandle, frag);
 
      glLinkProgram(programHandle);
       
       GLint status;
        glGetProgramiv(programHandle, GL_LINK_STATUS, &status);
         if(status == GL_FALSE)
         {
   LOG_FATAL("Error linking shaders! " + getProgInfo(programHandle));
         }

      // printActiveAttribs();
       printActiveUniforms();

           glDetachShader(programHandle, vert);
            glDetachShader(programHandle, frag);
             glDeleteShader(vert);
              glDeleteShader(frag);

      glUseProgram(programHandle);
}

void Scene::printActiveAttribs()
{
          GLint nAttrib;
           GLsizei written;
             GLint size;
              GLenum type;
               GLint maxLen;
                 GLchar* name;
                   GLint location;

  glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLen);
   glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTES, &nAttrib);

         name = new GLchar[maxLen];
          LOG_INFO("Active attributes:");
           for(GLuint i=0;i<nAttrib;++i)
          {
   glGetActiveAttrib(programHandle, i, maxLen, &written, &size, &type,
                                      name);
       location = glGetAttribLocation(programHandle, name);
    LOG_INFO(to_string(location) + " "
                                 + to_string(name) + " "
                                 + getTypeString(type));
         }
      delete[] name;
}

void Scene::printActiveUniforms()
{
          GLint nUniforms;
           GLint location;
               GLint size;

                 GLint maxLen;

                   GLsizei written;
                    GLenum type;
                       GLchar* name;

  glGetProgramiv(programHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLen);
   glGetProgramiv(programHandle, GL_ACTIVE_UNIFORMS, &nUniforms);

         name = new GLchar[maxLen];
          LOG_INFO("Active uniforms:");
           for(GLuint i=0;i<nUniforms;++i)
          {
   glGetActiveUniform(programHandle, i, maxLen, &written, &size, &type,
                                      name);
       location = glGetUniformLocation(programHandle, name);
    LOG_INFO(to_string(location) + " "
                                 + to_string(name) + " "
                                 + getTypeString(type));
         }
      delete[] name;
}

std::string Scene::getTypeString(GLenum glType)
{
   switch (glType)
  {
    case GL_INT:
      return "int";
       case GL_UNSIGNED_INT:
        return "uint";
    case GL_DOUBLE:
        return "double";
    case GL_BOOL:
         return "bool";
     case GL_FLOAT:
       return "float";
    case GL_FLOAT_VEC2:
        return "vec2";
       case GL_FLOAT_VEC3:
          return "vec3";
           case GL_FLOAT_VEC4:
             return "vec4";
          case GL_FLOAT_MAT2:
               return "mat2";
            case GL_FLOAT_MAT3:
                return "mat3";
              case GL_FLOAT_MAT4:
                  return "mat4";
    default:
      return "Unknown GL type";
   }
}

std::string Scene::getShaderInfo(GLuint shader)
{
        GLint logLen;
          glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);

           std::string log;
         if(logLen > 0)
          {
             log.resize(logLen, ' ');
              GLsizei written;
                glGetShaderInfoLog(shader, logLen, &written, &log[0]);
          }

   return log;
}
std::string Scene::getProgInfo(GLuint prog)
{
        GLint logLen;
          glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logLen);

            std::string log;
              if(logLen > 0)
               {
                  log.resize(logLen, ' ');
                    GLsizei written;
                 glGetShaderInfoLog(prog, logLen, &written, &log[0]);
               }

   return log;
}
