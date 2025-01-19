#pragma once


#include "Base.hpp"


template<typename T>
class UniformVariable
{
   public:
    template<typename... Args>
    UniformVariable(const char* name, Args... args)
    {
    m_size = sizeof...(args);
    m_name = name;
    m_uniformValues = std::make_shared<T*[]>(m_size);

    T* argList[sizeof...(args)] = {(args)...};
    
    for(unsigned int i = 0; i < m_size ; i++)
    {
    m_uniformValues.get()[i] = argList[i];
    }
    }
   
    template<typename... Args>
    UniformVariable(const char* name, std::vector<T>& userUniform, Args... args)
    {
    m_size = sizeof...(args);
    m_name = name;
    m_uniformValues = std::make_shared<T*[]>(m_size);

    T argList[sizeof...(args)] = {(args)...};

    for(unsigned long i = 0; i < m_size; i++)
    {
    userUniform.push_back(argList[i]);
    }
    
    for(unsigned int i = 0; i < m_size ; i++)
    {
    m_uniformValues.get()[i] = &(userUniform[i]);
    }
    }

    String name() const
    {
    return m_name;
    }

    T uniformAt(unsigned long idx) const
    {
    return *(m_uniformValues.get()[idx]);
    }

    T* uniformPtr(u64_t idx) const
    {
    return m_uniformValues.get()[idx];
    }

    T** getUniformData()
    {
    return m_uniformValues.get();
    }

    u64_t size() const
    {
    return m_size;
    }


    void createUniformLink(unsigned long idx, T* val)
    {
    m_uniformValues.get()[idx] = val;
    }

    void printUniforms() const
    {
    std::cout << "Uniform name: " << m_name << '\n';
    for(unsigned int i = 0; i < m_size;i++)
    {
    // std::cout << *(m_uniformValues.get()[i]) << '\n';
    }
    }

   private:
    // const char* m_name;
    String m_name;
    SharedPtr<T*[]> m_uniformValues;
    u64_t m_size;
};

// [ Have pure vitual uniform list class so less expensive ]
class UniformList
{
   public:
    UniformList() = default;
    ~UniformList() = default;

    void addUniform(const UniformVariable<bool>& uniform,
                    i32_t loc)
    {
    m_boolUniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }

    void addUniform(const UniformVariable<i32_t>& uniform,
                    i32_t loc)
    {
    m_intUniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }
    void addUniform(const UniformVariable<float>& uniform,
                    i32_t loc)
    {
    m_floatUniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }
    void addUniform(const UniformVariable<u32_t>& uniform,
                    i32_t loc)
    {
    m_unsignedIntUniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }
    void addUniform(const UniformVariable<Vec2>& uniform,
                    i32_t loc)
    {
    m_vec2Uniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }
    void addUniform(const UniformVariable<Vec3>& uniform,
                    i32_t loc)
    {
    m_vec3Uniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }
    void addUniform(const UniformVariable<Vec4>& uniform,
                    i32_t loc)
    {
    m_vec4Uniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }
    void addUniform(const UniformVariable<Mat2>& uniform,
                    i32_t loc)
    {
    m_mat2Uniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }
    void addUniform(const UniformVariable<Mat3>& uniform,
                    i32_t loc)
    {
    m_mat3Uniforms.push_back(uniform);
    m_uniformLocations[uniform.name()] = loc;
    }
    void addUniform(const UniformVariable<Mat4>& uniform,
                    i32_t loc)
    {
    m_mat4Uniforms.push_back(uniform);
    // std::cout << uniform.name() << " " << loc << '\n';
    m_uniformLocations[uniform.name()] = loc;
    // std::cout << m_uniformLocations[uniform.name()] << '\n';
    }

    void setUniform(const UniformVariable<i32_t>& uniform)
    {
    for(UniformVariable<int32_t>& a : m_intUniforms)
    {
    if(strcmp(a.name().c_str(), uniform.name().c_str()) == 0)
    {
    for(unsigned long i = 0; i < uniform.size(); i++)
    {
    int32_t** aPtr = a.getUniformData();
    int32_t* uPtr = uniform.uniformPtr(i);
    aPtr[i] = uPtr;
    }
    return;
    }
    }

    LOG_WARN("Couldn't find uniform when setting");
    }
    void setUniform(const UniformVariable<float>& uniform)
    {
    for(UniformVariable<float>& a : m_floatUniforms)
    {
    if(strcmp(a.name().c_str(), uniform.name().c_str()) == 0)
    {
    for(unsigned long i = 0; i < uniform.size(); i++)
    {
    float** aPtr = a.getUniformData();
    float* uPtr = uniform.uniformPtr(i);
    aPtr[i] = uPtr;

    }
    return;
    }
    }

    LOG_WARN("Couldn't find uniform when setting");
    }
    void setUniform(const UniformVariable<u32_t>& uniform)
    {
    for(UniformVariable<uint32_t>& a : m_unsignedIntUniforms)
    {
    if(strcmp(a.name().c_str(), uniform.name().c_str()) == 0)
    {
    for(unsigned long i = 0; i < uniform.size(); i++)
    {
    uint32_t** aPtr = a.getUniformData();
    uint32_t* uPtr = uniform.uniformPtr(i);
    aPtr[i] = uPtr;

    }
    return;
    }
    }
    }
    void setUniform(const UniformVariable<Mat4>& uniform)
    {
    for(UniformVariable<Mat4>& a : m_mat4Uniforms)
    {
    if(strcmp(a.name().c_str(), uniform.name().c_str()) == 0)
    {
    Mat4** aPtr = a.getUniformData();
    Mat4* uPtr = uniform.uniformPtr(0);
    aPtr[0] = uPtr;
    return;
    }
    }
    }

    Vector<UniformVariable<bool>> getBoolUniforms()
    {
    return m_boolUniforms;
    }
    Vector<UniformVariable<i32_t>> getIntUniforms()
    {
    return m_intUniforms;
    }
    Vector<UniformVariable<float>> getFloatUniforms()
    {
    return m_floatUniforms;
    }
    Vector<UniformVariable<u32_t>> getUnsignedIntUniforms()
    {
    return m_unsignedIntUniforms;
    }
    Vector<UniformVariable<Vec2>> getVec2Uniforms()
    {
    return m_vec2Uniforms;
    }
    Vector<UniformVariable<Vec3>> getVec3Uniforms()
    {
    return m_vec3Uniforms;
    }
    Vector<UniformVariable<Vec4>> getVec4Uniforms()
    {
    return m_vec4Uniforms;
    }
    Vector<UniformVariable<Mat2>> getMat2Uniforms()
    {
    return m_mat2Uniforms;
    }
    Vector<UniformVariable<Mat3>> getMat3Uniforms()
    {
    return m_mat3Uniforms;
    }
    Vector<UniformVariable<Mat4>> getMat4Uniforms()
    {
    return m_mat4Uniforms;
    }

    UniformVariable<Mat4> getMat4UniformFromListByName(const char* name)
    {
    for(const UniformVariable<Mat4>& uniform : m_mat4Uniforms)
    {
    if(strcmp(uniform.name().c_str(), name) == 0)
    {
    return uniform;
    }
    }


    // Returning a null mat4, maybe creating shared a getting
    // underlying ptr will cause bugs
    LOG_WARN("Couldn't find uniform, returing invalid mat");
    return UniformVariable<Mat4>{"Null", createShared<Mat4>().get()};
    }
    
    void printMat4UniformList()
    {
    for(const UniformVariable<Mat4>& uniform : m_mat4Uniforms)
    {
    float x0y0 = uniform.uniformAt(0)[0][0];
    float x1y0 = uniform.uniformAt(0)[1][0];
    float x2y0 = uniform.uniformAt(0)[2][0];
    float x3y0 = uniform.uniformAt(0)[3][0];
    float x0y1 = uniform.uniformAt(0)[0][1];
    float x1y1 = uniform.uniformAt(0)[1][1];
    float x2y1 = uniform.uniformAt(0)[2][1];
    float x3y1 = uniform.uniformAt(0)[3][1];
    float x0y2 = uniform.uniformAt(0)[0][2];
    float x1y2 = uniform.uniformAt(0)[1][2];
    float x2y2 = uniform.uniformAt(0)[2][2];
    float x3y2 = uniform.uniformAt(0)[3][2];
    float x0y3 = uniform.uniformAt(0)[0][3];
    float x1y3 = uniform.uniformAt(0)[1][3];
    float x2y3 = uniform.uniformAt(0)[2][3];
    float x3y3 = uniform.uniformAt(0)[3][3];

    LOG_INFO("Uniform name: {}\n Uniform values: [{} {} {} {}]\n                 [{} {} {} {}]\n                 [{} {} {} {}]\n                 [{} {} {} {}]");
    }

    }

    void printUniformList()
    {
    for(const auto& uniform : m_intUniforms)
    {
    for(u64_t i = 0; i < uniform.size(); i++)
    {
    LOG_INFO("Uniform value: {}");
    }
    }


    for(const auto& uniform : m_floatUniforms)
    {
    for(u64_t i = 0; i < uniform.size(); i++)
    {
    LOG_INFO("Uniform value: {}");
    }
    }

    for(const auto& uniform : m_unsignedIntUniforms)
    {
    for(u64_t i = 0; i < uniform.size(); i++)
    {
    LOG_INFO("Uniform value: {}");
    }
    }

    for(const auto& uniform : m_vec2Uniforms)
    {
    LOG_INFO("Uniform value: {} {}");
    }

    for(const auto& uniform : m_vec3Uniforms)
    {
    LOG_INFO("Uniform value: {} {} {}");
    }

    for(const auto& uniform : m_vec4Uniforms)
    {
    LOG_INFO("Uniform value: {} {} {} {}");
    }

    for(const auto& uniform : m_mat4Uniforms)
    {
    LOG_INFO("Uniform name: {}");
    uniform.printUniforms();
    }

    }

    void setUniformLocations(Map<String, i32_t> uniformLocations)
    {
    m_uniformLocations = uniformLocations;
    }

    Map<String, i32_t> uniformLocations() const
    {
    return m_uniformLocations;
    }


   private:
    Vector<UniformVariable<bool>> m_boolUniforms;
    Vector<UniformVariable<i32_t>> m_intUniforms;
    Vector<UniformVariable<float>> m_floatUniforms;
    Vector<UniformVariable<u32_t>> m_unsignedIntUniforms;

    // [ Only taking into account float vectors
    //   and matricies, should be aware user
    //   may want to pass in other types ]

    Vector<UniformVariable<Vec2>> m_vec2Uniforms;
    Vector<UniformVariable<Vec3>> m_vec3Uniforms;
    Vector<UniformVariable<Vec4>> m_vec4Uniforms;
    Vector<UniformVariable<Mat2>> m_mat2Uniforms;
    Vector<UniformVariable<Mat3>> m_mat3Uniforms;
    Vector<UniformVariable<Mat4>> m_mat4Uniforms;

    Map<String, i32_t> m_uniformLocations;
};

struct UniformLoc
{
   public:
    const char* m_name;
    int m_loc;
};
