
#include "GLSLProg.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

GLSLProg::GLSLProg()
: m_prog{0}
{
    m_typeMap = 
    {
    {"vert", GL_VERTEX_SHADER},
    {"Vert", GL_VERTEX_SHADER},
    {"vertex", GL_VERTEX_SHADER},
    {"frag", GL_FRAGMENT_SHADER},
    {"Frag", GL_FRAGMENT_SHADER},
    {"fragment", GL_FRAGMENT_SHADER},
    {"none", 0}
    };
}

GLSLProg::~GLSLProg()
{
     deleteAttachedShaders();
}

void GLSLProg::compileShader(const char* fname)
{
    if(m_prog == 0)
    {
    m_prog = glCreateProgram();
    }

    std::ifstream ifs{fname};
    if(!ifs)
    {
    std::cout << "Could open file!" << "\n";
    }

    GLenum type = queryType(fname);

    unsigned int shader;
    shader = glCreateShader(type);

    std::stringstream streamShader;
    streamShader << ifs.rdbuf();

    std::string strShader{streamShader.str()};
    const char* shaderSrc{strShader.c_str()};

    glShaderSource(shader, 1, &shaderSrc, NULL);
    glCompileShader(shader);

    checkCompileStatus(shader);

    glAttachShader(m_prog, shader);
}

void GLSLProg::linkShaders()
{
    if(m_prog == 0)
    {
    std::cout << "No program handle!\n";
    }

    glLinkProgram(m_prog);

    checkLinkStatus();

    deleteAttachedShaders();
}

void GLSLProg::use()
{
    if(m_prog == 0)
    {
    std::cout << "Invalid shader program handle\n"; 
    }
    glUseProgram(m_prog);
}

void GLSLProg::checkCompileStatus(GLuint shader)
{
    int status;
    char logLoad[500];

    GLint type;
    glGetShaderiv(shader, GL_SHADER_TYPE, &type);
    const char* typeStr = typeToCString(GLenum(type));

    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if(!status)
    {
    glGetShaderInfoLog(shader, 500, NULL, logLoad);
    std::cout << typeStr << " error: " << logLoad << "\n";
    }
    }

void GLSLProg::checkLinkStatus()
{
    if(m_prog == 0)
    {
    std::cout << "No program handle!\n";
    }

    int status;
    char logLoad[500];

    glGetProgramiv(m_prog, GL_LINK_STATUS, &status);

    if(!status)
    {
    glGetProgramInfoLog(m_prog, 500, NULL, logLoad);
    std::cout << "Linking error: " << logLoad << "\n";
    }
}

void GLSLProg::addUniform(const char* name)
{
    GLint loc =  glGetUniformLocation(m_prog, name);
    m_uniformLoc.push_front(UniformLoc{name, loc});
}

void GLSLProg::addUniform(const char* name, int& loc)
{
    loc =  glGetUniformLocation(m_prog, name);
    m_uniformLoc.push_front(UniformLoc{name, loc});
}

void GLSLProg::setUniforms(UniformList& uniforms)
{

}

void GLSLProg::setUniform(i32_t loc, float x)
{
    glUniform1f(loc, x);
}

void GLSLProg::setUniform(i32_t loc, float x, float y)
{
    glUniform2f(loc, x, y);
}

void GLSLProg::setUniform(i32_t loc, float x, float y, float z)
{
    glUniform3f(loc, x, y, z);
}

void GLSLProg::setUniform(i32_t loc, float x, float y, float z, float w)
{
    glUniform4f(loc, x, y, z, w);
}

void GLSLProg::setUniform(i32_t loc, i32_t x)
{
    glUniform1i(loc, x);
}

void GLSLProg::setUniform(i32_t loc, i32_t x, i32_t y)
{
    glUniform2i(loc, x, y);
}

void GLSLProg::setUniform(i32_t loc, i32_t x, i32_t y, i32_t z)
{
    glUniform3i(loc, x, y, z);
}

void GLSLProg::setUniform(i32_t loc, i32_t x, i32_t y, i32_t z, i32_t w)
{
    glUniform4i(loc, x, y, z, w);
}

void GLSLProg::setUniform(i32_t loc, u32_t x)
{
    glUniform1ui(loc, x);
}

void GLSLProg::setUniform(i32_t loc, u32_t x, u32_t y)
{
    glUniform2ui(loc, x, y);
}

void GLSLProg::setUniform(i32_t loc, u32_t x, u32_t y, u32_t z)
{
    glUniform3ui(loc, x, y, z);
}

void GLSLProg::setUniform(i32_t loc, u32_t x, u32_t y, u32_t z, u32_t w)
{
    glUniform4ui(loc, x, y, z, w);
}

void GLSLProg::setUniform(i32_t loc, glm::mat2 mat)
{
    glUniformMatrix2fv(loc, 1, GL_FALSE, &mat[0][0]);
}

void GLSLProg::setUniform(i32_t loc, glm::mat3 mat)
{
    glUniformMatrix3fv(loc, 1, GL_FALSE, &mat[0][0]);
}

void GLSLProg::setUniform(i32_t loc, glm::mat4 mat)
{
    glUniformMatrix4fv(loc, 1, GL_FALSE, &mat[0][0]);
}

void GLSLProg::setUniform(i32_t loc, glm::vec2 vec)
{
    glUniform2f(loc, vec.x, vec.y);
}

void GLSLProg::setUniform(i32_t loc, glm::vec3 vec)
{
    glUniform3f(loc, vec.x, vec.y, vec.z);
}

void GLSLProg::setUniform(i32_t loc, glm::vec4 vec)
{
    glUniform4f(loc, vec.x, vec.y, vec.z, vec.w);
}

void GLSLProg::setUniform(i32_t loc, int32_t count, float* floatList)
{
    glUniform1fv(loc, count, floatList);
    // loc = findUniformLocation(uniformSizeName.get());
    // glUniform1ui(loc, static_cast<uint32_t>(strlen(uniformSizeName.get())));
}

i32_t GLSLProg::findUniformLocation(const char* name)
{
    return glGetUniformLocation(m_prog, name);
}

int32_t GLSLProg::activeUniformsAmount()
{
    int32_t activeUniformAmount = 0;
    glGetProgramiv(m_prog, GL_ACTIVE_UNIFORMS, &activeUniformAmount);

    return activeUniformAmount;
}

void GLSLProg::setUniform(i32_t loc, bool uniform)
{
    glUniform1f(loc, uniform);
}

void GLSLProg::printUniformLocations()
{
   for(auto& a : m_uniformLoc)
   {
   std::cout << a.m_name << '\n';
   } 
}

void GLSLProg::queryActiveUniformName(i32_t loc,
                                      i32_t bufSize,
                                      i32_t* length,
                                      char* uniformName)
{
    glGetActiveUniformName(m_prog,
                           static_cast<u32_t>(loc),
                           bufSize,
                           length,
                           uniformName
                          );
}

// int GLSLProg::findUniformLocation(const char* name)
// {
//     for(auto& a : m_uniformLoc)
//     {
//     if(std::strcmp(name, a.m_name) == 0)
//     {
//     return a.m_loc;
//     }
//     } 
//
//     int loc;
//     addUniform(name, loc);
//
//     return loc;
// }

GLenum GLSLProg::queryType(const char* fname)
{
    auto newStr = std::make_unique<char[]>(std::strlen(fname) + 1);
    std::strcpy(newStr.get(), fname);

    unsigned long extSize = 0;
    unsigned long numExtentions = 0;

    for(auto i = newStr.get(); *i != '\0'; i++)
    {
    if(*i == '.')
    {
    numExtentions++;
    }
    }

    auto extensionAmount = std::make_unique<unsigned long[]>(numExtentions);
    auto extensionLoc = std::make_unique<unsigned long[]>(numExtentions);

    unsigned long extAmountIdx = 0;
    const char* ext = newStr.get();

    unsigned long idx = 0; 

    for(auto i = newStr.get(); *i != '\0'; i++)
    {
    if(*i == '.')
    {
    ext += idx + 1;
    for(; *ext != '.'; ext++)
    {
    if(*ext == '\0')
    {
    break;
    }

    extSize++;
    }

    ext = newStr.get();

    extensionLoc[extAmountIdx] = idx;

    extensionAmount[extAmountIdx] = extSize;
    extAmountIdx++;
    extSize = 0;
    }
    idx++;
    }

    auto extension = std::make_unique<char[]>(extensionAmount[0]);
    auto glsl = std::make_unique<char[]>(extensionAmount[1]);

    for(unsigned long i = 0; i < extensionAmount[0]; i++)
    {
    extension[i] = newStr[i + extensionLoc[0] + 1];
    }

    for(unsigned long i = 0; i < extensionAmount[1]; i++)
    {
    glsl[i] = newStr[i + extensionLoc[1] + 1];
    }

    for(const auto& [key, val] : m_typeMap)
    {
    if(std::strcmp(extension.get(), key) == 0)
    {
    return val;
    // return convertGLType()
    }
    }

    return m_typeMap["none"];
}

const char* GLSLProg::typeToCString(GLenum type)
{
    switch (type) 
    {
    case GL_VERTEX_SHADER:
    return "vertex shader";
    case GL_FRAGMENT_SHADER:
    return "fragment shader";
    default:
    return "Not a valid type";
    }
    return "Not a valid type";
}

void GLSLProg::deleteAttachedShaders()
{
    GLint count;
    glGetProgramiv(m_prog, GL_ATTACHED_SHADERS, &count);
    auto shaders = std::make_unique<GLuint[]>(GLuint(count));

    glGetAttachedShaders(m_prog,
                         sizeof(shaders.get()),
                         NULL,
                         shaders.get()
                         );

    for(GLuint i = 0; i < GLuint(count); i++)
    {
    glDeleteShader(shaders[i]);
    }
}
