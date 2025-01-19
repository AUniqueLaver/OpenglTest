
#include "Cube.hpp"


      // ny(p0z - p1z) - nz(p0y - p1y)
      // nz(p0x - p1x) - nx(p0z - p1z)
      // nx(p0y - p1y) - ny(p0x - p1x)
      //
      // nyp0z - nyp1z - nzp0y + nzp1y
      // nzp0x - nzp1x - nxp0z + nxp1z
      // nxp0y - nxp1y - nyp0x + nyp1x
      //
      // 

      // n . (p0 - p1) = 0
      // np0x - np1x + np0y - np1y + np0z - np1z = 
      // = np0x + np0y + np0z = np1x + np2y + np3z
      //
      // nx, ny, nz
      //
      //
      // D = np1x + np2y + np3z
      //
      // Ax + By + Cz = D
      // 
      //
      // Ax = -0.5nx
      //
      // By =  0.5ny
      //
      // Cz =  0.5nz
      //
      // D = 0.5nx + 0.5ny + 0.5nz
      //
      //
      // -0.5nx + 0.5ny + 0.5nz = 0.5nx + 0.5ny + 0.5nz
      //
      // -1nx + 0ny + 0nz = 0;
      //
      // nx = 0;
      // ny = 0;
      // nz = 0;
      //
      //

void printVectorInformationVec3(glm::vec3 vec)
{
    std::cout << vec.x << " " << vec.y << " " << vec.z << '\n';
}
void printVectorInformationVec4(glm::vec4 vec)
{
    std::cout << vec.x << " " << vec.y << " " << vec.z << " " << vec.z << '\n';
}

void printMat3(glm::mat3 mat)
{
    for(int32_t i=0;i<3;i++)
    {
    for(int32_t j=0;j<3;j++)
    {
    std::cout << mat[i][j] << " ";
    }
    std::cout << '\n';
    }
}

void printMat4(glm::mat4 mat)
{
    for(int32_t i=0;i<4;i++)
    {
    for(int32_t j=0;j<4;j++)
    {
    std::cout << mat[i][j] << " ";
    }
    std::cout << '\n';
    }

}

Cube::Cube()
: m_modelPosition{glm::vec3{0.0f}},
  m_modelScale{glm::vec3{1.0f}},
  m_vaoHandle{0},
  m_texture{0},
  m_specularMap{0},
  m_indicies{std::vector<uint32_t>{}},
  m_shaderProgram{GLSLProg{}},
  m_model{glm::mat4{1.0f}},
  m_view{glm::mat4{1.0f}},
  m_proj{glm::mat4{1.0f}},
  m_normalMatrix{glm::mat4{1.0f}},
  m_material{Material{}}
{

}

Cube::~Cube()
{

}

void Cube::init(CreateData data)
{
    m_shaderProgram.compileShader(data.vertexShader());
    m_shaderProgram.compileShader(data.fragmentShader());
    m_shaderProgram.linkShaders();

    addUniform(UniformVariable<glm::mat4>{"model", &m_model});
    addUniform(UniformVariable<glm::mat4>{"view", &m_view});
    addUniform(UniformVariable<glm::mat4>{"proj", &m_proj});
    addUniform(UniformVariable<glm::mat4>{"normalMatrixUser", &m_normalMatrix});

    addUniform(UniformVariable<glm::vec3>{"material.m_ambient", &m_material.ambient()});
    addUniform(UniformVariable<glm::vec3>{"material.m_diffuse", &m_material.diffuse()});
    addUniform(UniformVariable<glm::vec3>{"material.m_specular.m_specular", &m_material.specular().specular()});
    addUniform(UniformVariable<float>{"material.m_specular.m_reflectiveness", &m_material.specular().reflectiveness()});
      

    int textureWidth = 0;
    int textureHeight = 0;
    int textureClrChannels = 0;

    // stbi_set_flip_vertically_on_load(true);
    unsigned char* textureData = stbi_load("Assets/Images/SpecularWriting.png", &textureWidth, &textureHeight, &textureClrChannels, 0);
    if(!textureData)
    {
    std::cout << "Error creating texture data\n";
    }


    glGenTextures(1, &m_texture);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(textureData);


    textureWidth = 0;
    textureHeight = 0;
    textureClrChannels =0;

    textureData = stbi_load("Assets/Images/MapSpecularWriting.png", &textureWidth, &textureHeight, &textureClrChannels, 0);
    // textureData = stbi_load("Assets/Images/MapSpecularCircle.png", &textureWidth, &textureHeight, &textureClrChannels, 0);
    if(!textureData)
    {
    std::cout << "Error creating texture data\n";
    }


    glGenTextures(1, &m_specularMap);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_specularMap);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(textureData);

    m_indicies = std::vector<uint32_t>
    {
    0, 2, 3,
    0, 1, 3,

    4, 5, 7,
    4, 6, 7,

    8, 9, 11,
    8, 10, 11,

    12, 13, 15,
    12, 14, 15,

    16, 17, 19,
    16, 18, 19,

    20, 21, 23,
    20, 22, 23
    };

    std::vector<float> positions
    {
     -0.5f,  0.5f,  0.5f,  
      0.5f,  0.5f,  0.5f,  
     -0.5f, -0.5f,  0.5f,  
      0.5f, -0.5f,  0.5f,  

      0.5f,  0.5f,  0.5f,  
      0.5f,  0.5f, -0.5f,  
      0.5f, -0.5f,  0.5f,  
      0.5f, -0.5f, -0.5f,  

     -0.5f,  0.5f, -0.5f,  
      0.5f,  0.5f, -0.5f,  
     -0.5f, -0.5f, -0.5f,  
      0.5f, -0.5f, -0.5f,  

     -0.5f,  0.5f,  0.5f,  
     -0.5f,  0.5f, -0.5f,  
     -0.5f, -0.5f,  0.5f,  
     -0.5f, -0.5f, -0.5f,  

     -0.5f,  0.5f, -0.5f,  
      0.5f,  0.5f, -0.5f,  
     -0.5f,  0.5f,  0.5f,  
      0.5f,  0.5f,  0.5f,  

     -0.5f, -0.5f,  0.5f,  
      0.5f, -0.5f,  0.5f,  
     -0.5f, -0.5f, -0.5f,
      0.5f, -0.5f, -0.5f
    };

    std::vector<glm::vec3> cubeNormals;  

    std::vector<glm::vec3> point;
    std::vector<float> storeFloats;

    for(uint32_t i = 0; i < positions.size(); i++)
    {
    storeFloats.push_back(positions[i]);
    if(((i + 1) % 3) == 0)
    {
    point.push_back(glm::vec3(storeFloats[0], storeFloats[1], storeFloats[2]));
    storeFloats.clear();
    }

    if(((i + 1) % 12) == 0)
    {
    cubeNormals.push_back(glm::cross((point[0] - point[1]), (point[0] - point[2])));
    point.clear();
    }

    }

    // std::vector<float> normals;
    std::vector<float> normals
    {
     0,  0,  1,
     0,  0,  1,
     0,  0,  1,
     0,  0,  1,

     1,  0,  0,
     1,  0,  0,
     1,  0,  0,
     1,  0,  0,

     0,  0, -1,
     0,  0, -1,
     0,  0, -1,
     0,  0, -1,

    -1,  0,  0,
    -1,  0,  0,
    -1,  0,  0,
    -1,  0,  0,

     0,  1,  0,
     0,  1,  0,
     0,  1,  0,
     0,  1,  0,

     0, -1,  0,
     0, -1,  0,
     0, -1,  0,
     0, -1,  0
    };

    // for(uint32_t i = 0; i < cubeNormals.size(); i++)
    // {
    // for(uint32_t j = 0; j < 4; j++)
    // {
    // if((i == 0) || (i == 1) || (i == 4) || (i == 5))
    // {
    // normals.push_back(-cubeNormals[i].x);
    // normals.push_back(-cubeNormals[i].y);
    // normals.push_back(-cubeNormals[i].z);
    //
    // }
    //
    // if(((i == 2) || (i == 3)))
    // {
    // normals.push_back(cubeNormals[i].x);
    // normals.push_back(cubeNormals[i].y);
    // normals.push_back(cubeNormals[i].z);
    // }
    //
    // }
    //
    // }
    //
    // for(uint32_t i = 0; i < normals.size(); i++)
    // {
    // std::cout << normals[i] << " ";
    // if(((i + 1) % 3) == 0)
    // {
    // std::cout << '\n';
    // }
    // }
 

    // glm::vec3 a0{-0.5f,  0.5f,  0.5f};  
    // glm::vec3 a1{0.5f,  0.5f,  0.5f}; 
    // glm::vec3 a2{-0.5f, -0.5f,  0.5f}; 

    // glm::vec3 normal = glm::cross(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f));
    // glm::vec3 normal = glm::cross((a1 - a0), (a2 - a0));
  
    std::vector<float> textureCoords
    {
      0.0f, 0.0f,
      1.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 1.0f,

      0.0f, 0.0f,
      1.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 1.0f,

      0.0f, 0.0f,
      1.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 1.0f,

      0.0f, 0.0f,
      1.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 1.0f,

      0.0f, 0.0f,
      1.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 1.0f,

      0.0f, 0.0f,
      1.0f, 0.0f,
      0.0f, 1.0f,
      1.0f, 1.0f,
    };
    

    unsigned int vboHandle = 0;

    uint32_t indexBuffer = 0;
    uint32_t positionBuffer = 0;
    uint32_t normalBuffer = 0;
    uint32_t textureCoordsBuffer = 0;

    glGenVertexArrays(1, &m_vaoHandle);
    glBindVertexArray(m_vaoHandle);  

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 static_cast<long>(m_indicies.size() * sizeof(uint32_t)),
                 m_indicies.data(),
                 GL_STATIC_DRAW
                 );
  
    glGenBuffers(1, &positionBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<long>(positions.size() * sizeof(float)),
                 positions.data(),
                 GL_STATIC_DRAW
                );

    glGenBuffers(1, &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<long>(normals.size() * sizeof(float)),
                 normals.data(),
                 GL_STATIC_DRAW);

    glGenBuffers(1, &textureCoordsBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, textureCoordsBuffer);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<long>(textureCoords.size() * sizeof(float)),
                 textureCoords.data(),
                 GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glVertexAttribPointer(1,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          0);

    glBindBuffer(GL_ARRAY_BUFFER, textureCoordsBuffer);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          0);

    // if(m_uniformBuffers.size() > 0)
    // {
    // u32_t uniformBlockBuffer = 0;
    // glGenBuffers(1, &uniformBlockBuffer);
    // u32_t uniformIndex = glGetUniformBlockIndex(m_shaderProgram.prog(), m_uniformBuffers[0]);
    //
    // glUniformBlockBinding(m_shaderProgram.prog(), uniformIndex, uniformBlockBuffer);
    // glBindBufferBase(GL_UNIFORM_BUFFER, uniformIndex, uniformBlockBuffer);

    // float colorUser[3] = {1,1,1};
    // glBufferStorage(GL_UNIFORM_BUFFER,
    //                 3 * sizeof(float),
    //                 colorUser,
    //                 GL_DYNAMIC_STORAGE_BIT
    //                );
    //
    // std::cout << "Uniform block: " << uniformIndex << '\n';
    // }

    glBindVertexArray(0);


    // m_material.setAmbient(glm::vec3{0.2125f, 0.1275f, 0.054f});
    // m_material.setDiffuse(glm::vec3{0.714f, 0.4284f, 0.18144f});
    // m_material.setSpecular(glm::vec3{0.393548f, 0.271906f, 0.166721f}, 25.6f);
  
    m_material.setAmbient(glm::vec3{0.1f});
    m_material.setDiffuse(glm::vec3{0.8f});
    m_material.setSpecular(glm::vec3{1.0f}, 25.6f);
  

    // m_light.setAmbient(glm::vec3{1.0f});
    // m_light.setDiffuse(glm::vec3{1.0f});
    // m_light.setSpecular(glm::vec3{1.0f});
  
    // m_light.setAmbient(glm::vec3{0.1f});
    // m_light.setDiffuse(glm::vec3{0.8f});
    // m_light.setSpecular(glm::vec3{1.0f});
}

void Cube::setPosition(glm::vec3 modelPosition)
{
    m_modelPosition = modelPosition;
}

void Cube::setScaleAmount(glm::vec3 modelScaleAmount)
{
    m_modelScale = modelScaleAmount;
}

void Cube::render(CameraData& cameraData, std::pair<int32_t, int32_t> windowDimensions)
{
    glBindVertexArray(m_vaoHandle);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_specularMap);

    m_view = glm::lookAt(cameraData.cam().position(),
                         cameraData.cam().front() + cameraData.cam().position(),
                         cameraData.cam().upDirection());

    m_proj = glm::mat4(1.0f);
    const float fov = cameraData.fov();
    m_proj = glm::perspective(glm::radians(fov), float(windowDimensions.first) / float(windowDimensions.second), 0.1f, 100.0f);

    m_model = glm::mat4(1.0f);

    m_model = glm::translate(m_model, m_modelPosition);
    m_model = glm::scale(m_model, m_modelScale);
    // model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 1.0f));
  
    // std::cout << "Uniform: " << m_shaderProgram.findUniformLocation("numUser") << '\n';

    m_normalMatrix = glm::inverse(glm::transpose(glm::mat3(m_model)));
  
    m_shaderProgram.use(); 

    // i32_t numUserLoc = m_shaderProgram.findUniformLocation("numUser[0].m_num");
    // glUniform3f(numUserLoc,
    //             m_material.specular().specular().x,
    //             m_material.specular().specular().y,
    //             m_material.specular().specular().z
    //             );
    // glUniform3f(numUserLoc + 3,
    //             m_material.specular().specular().x,
    //             m_material.specular().specular().y,
    //             m_material.specular().specular().z
    //            );
  
    for(UniformVariable<int32_t>& uniform : m_uniforms.getIntUniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];
    switch(uniform.size())
    {
    case 1:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0));
    break;
    case 2:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1));
    break;
    case 3:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1),
                               uniform.uniformAt(2));
    break;
    case 4:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1),
                               uniform.uniformAt(2),
                               uniform.uniformAt(3));
    break;
    }
    }

    for(UniformVariable<uint32_t>& uniform : m_uniforms.getUnsignedIntUniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];
    switch(uniform.size())
    {
    case 1:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0));
    break;
    case 2:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1));
    break;
    case 3:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1),
                               uniform.uniformAt(2));
    break;
    case 4:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1),
                               uniform.uniformAt(2),
                               uniform.uniformAt(3));
    break;
    }
    }

    for(UniformVariable<float>& uniform : m_uniforms.getFloatUniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];
    switch(uniform.size())
    {
    case 1:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0));
    break;
    case 2:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1));
    break;
    case 3:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1),
                               uniform.uniformAt(2));
    break;
    case 4:
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0),
                               uniform.uniformAt(1),
                               uniform.uniformAt(2),
                               uniform.uniformAt(3));
    break;
    }
    }

    for(UniformVariable<Vec2>& uniform : m_uniforms.getVec2Uniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0).x,
                               uniform.uniformAt(0).y);
    }
    for(UniformVariable<Vec3>& uniform : m_uniforms.getVec3Uniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0).x,
                               uniform.uniformAt(0).y,
                               uniform.uniformAt(0).z);
    }
    for(UniformVariable<Vec4>& uniform : m_uniforms.getVec4Uniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0).x,
                               uniform.uniformAt(0).y,
                               uniform.uniformAt(0).z,
                               uniform.uniformAt(0).w);
    }
    for(UniformVariable<Mat2>& uniform : m_uniforms.getMat2Uniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0));
    }
    for(UniformVariable<Mat3>& uniform : m_uniforms.getMat3Uniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];
    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0));
    }

    for(UniformVariable<Mat4>& uniform : m_uniforms.getMat4Uniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];

    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0));
    }

    for(UniformVariable<bool>& uniform : m_uniforms.getBoolUniforms())
    {
    i32_t loc = m_uniforms.uniformLocations()[uniform.name().c_str()];

    m_shaderProgram.setUniform(loc,
                               uniform.uniformAt(0));
    }

    // i32_t listLoc = m_shaderProgram.findUniformLocation("lightList[0].m_directional");
    // glUniform3f(listLoc,
    //             m_material.specular().specular().x,
    //             m_material.specular().specular().y,
    //             m_material.specular().specular().z
    //             );
    // glUniform3f(listLoc + 1,
    //             m_material.specular().specular().x,
    //             m_material.specular().specular().y,
    //             m_material.specular().specular().z
    //            );
  
    // i32_t listLoc = m_shaderProgram.findUniformLocation("lightList[0].m_directional");
    // glUniform1i(listLoc + 23,
    //             true
    //             );

    // std::cout << m_shaderProgram.activeUniformsAmount() << '\n';
  
    // i32_t modelLoc = m_uniforms.uniformLocations()["model"];
    // m_shaderProgram.setUniform(modelLoc,
    //                            uniform.uniformAt(0));
    // i32_t viewLoc = m_uniforms.uniformLocations()["view"];
    // m_shaderProgram.setUniform(viewLoc,
    //                            uniform.uniformAt(0));
    // i32_t projLoc = m_uniforms.uniformLocations()["proj"];
    // m_shaderProgram.setUniform(projLoc,
    //                            uniform.uniformAt(0));

    // std::cout << "model\n";
    // printMat4(m_model);
    // std::cout << "view\n";
    // printMat4(m_view);
    // std::cout << "proj\n";
    // printMat4(m_proj);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);

    glBindVertexArray(0);
};
