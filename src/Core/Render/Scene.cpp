#include "Scene.hpp"
#include "Core/Log.hpp"

#include <fstream>
#include <sstream>

Scene::Scene()
{   

}
void Scene::update(float dt) 
{

}
void Scene::render() 
{
                glClear(GL_COLOR_BUFFER_BIT);

                  glBindVertexArray(vaoHandle);
                   glDrawArrays(GL_TRIANGLES, 0, 3);
                    glBindVertexArray(0);
}
void Scene::initScene() 
{
     compileShaderProg();

       float posData[] = 
        {
             -0.8f, -0.8f, 0.0f,
              0.8f, -0.8f, 0.0f,
              0.0f,  0.8f, 0.0f
        };
   
       float colData[] =
        {
             1.0f, 0.0f, 0.0f,
             0.0f, 1.0f, 0.0f,
             0.0f, 0.0f, 1.0f
        };

    GLuint vboHandles[2];
      glGenBuffers(2, vboHandles);
       GLuint posBufferHandle = vboHandles[0];
        GLuint colBufferHandle = vboHandles[1];
   
    glBindBuffer(GL_ARRAY_BUFFER, posBufferHandle);
      glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), posData, GL_STATIC_DRAW);

       glBindBuffer(GL_ARRAY_BUFFER, colBufferHandle);
        glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colData, GL_STATIC_DRAW);

       glGenVertexArrays(1, &vaoHandle);
        glBindVertexArray(vaoHandle);

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

void Scene::compileShaderProg()
{
  std::ifstream vertFile("Assets/basic_vert.glsl");
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

      std::ifstream fragFile("Assets/basic_frag.glsl");
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
        glGetShaderiv(programHandle, GL_LINK_STATUS, &status);
         if(status == GL_FALSE)
         {
         LOG_FATAL("Error linking shaders! " + getProgInfo(programHandle));
         }

           glDetachShader(programHandle, vert);
            glDetachShader(programHandle, frag);
             glDeleteShader(vert);
              glDeleteShader(frag);

      glUseProgram(programHandle);
}
void Scene::loadShaderBin(GLuint format)
{
    std::cout << "Loading shader binary with format: " << format << std::endl;

  programHandle = glCreateProgram();
   if(programHandle == 0)
    {
         LOG_FATAL("Error creating program handle");
    }

        std::ifstream ifs("Assets/shdaerProgram.bin", std::ios::binary);

     std::istreambuf_iterator<char> begin(ifs);
      std::istreambuf_iterator<char> end;
        std::vector<char> buffer(begin, end);
    ifs.close();
    
     glProgramBinary(programHandle, format, buffer.data(), buffer.size());

    GLint result;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &result);
     if(result == 0)
      {
         LOG_FATAL("Error linking shader program " + getProgInfo(programHandle));
      }
   
   glUseProgram(programHandle);
}
void Scene::writeShaderBin()
{
      GLint formats;
        glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &formats);

      if(formats > 0)
        {
           GLint length;
    glGetProgramiv(programHandle, GL_PROGRAM_BINARY_LENGTH, &length);
      std::cout << "Program binary length: " << length << std::endl;

       std::vector<GLubyte> buffer;
        GLenum format;
glGetProgramBinary(programHandle, length , NULL, &format, buffer.data());
      std::string fname("Assets/shaderProg.bin");

       //Todo: Add GLint to string
    
           // LOG_INFO("Writing to: " + fname + ", with binary format: " + format);
            LOG_INFO("Writing to: " + fname + ", with binary format: ");

            std::ofstream ofs(fname.c_str(), std::ios::binary);
              ofs.write(reinterpret_cast<char*>(buffer.data()), length);
               ofs.close();
        }
    else
       LOG_ERROR("No binary formats suppported by this driver, unable to wrtie shader binary");
}
void Scene::loadSpirvShader()
{
     GLint status;

      GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
   
    std::ifstream vertIfs("Assets/vert.spv", std::ios::binary);
      std::istreambuf_iterator<char> vertB(vertIfs);
        std::istreambuf_iterator<char> vertEos;
     std::vector<char> vbuffer(vertB, vertEos);
       vertIfs.close();
   
  glShaderBinary(1, &vertShader, GL_SHADER_BINARY_FORMAT_SPIR_V_ARB,
                                                    vbuffer.data(), 
                                                    vbuffer.size());

      glSpecializeShaderARB(vertShader, "main", 0, 0, 0);

    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &status);
  if(status == GL_FALSE)
      {
         LOG_ERROR("Error compiling vertex shader " + getShaderInfo(vertShader));
      }

      GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
        
         std::ifstream fragIfs("Assets/frag.spv", std::ios::binary);
          std::istreambuf_iterator<char> fragB(fragIfs);
           std::istreambuf_iterator<char> fragEos;
            std::vector<char> fbuffer(fragB, fragEos);
         fragIfs.close();
      
       glShaderBinary(1, &fragShader, GL_SHADER_BINARY_FORMAT_SPIR_V_ARB,
                                                       fbuffer.data(),
                                                        fbuffer.size());

           glSpecializeShaderARB(fragShader, "main", 0, 0, 0);
     
      glGetShaderiv(fragShader, GL_COMPILE_STATUS, &status);
        if(status == GL_FALSE)
            {
               LOG_ERROR("Error compiling fragment shader " + getShaderInfo(fragShader));
            }
        
      programHandle = glCreateProgram();
        if(programHandle == 0)
          {
             LOG_FATAL("Error creating program handle");
          }

      glAttachShader(programHandle, vertShader);
        glAttachShader(programHandle, fragShader);
    
     glLinkProgram(programHandle);
      
        glGetShaderiv(programHandle, GL_LINK_STATUS, &status);
         if(status == GL_FALSE)
         {
              LOG_FATAL("Error linking shaders! " + getProgInfo(programHandle));
         }
   
       glUseProgram(programHandle);
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
