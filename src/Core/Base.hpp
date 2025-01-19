#pragma once

#include <cstdint>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <iostream>
#include <memory>


template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T>
using Vector = std::vector<T>;

using String = std::string;

template<typename T, typename D>
using Map = std::map<T, D>;

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using Vec2 = glm::vec2;
using Vec3 = glm::vec3;
using Vec4 = glm::vec4;

using Mat2 = glm::mat2;
using Mat3 = glm::mat3;
using Mat4 = glm::mat4;


using i16_t = int16_t;
using i32_t = int32_t;
using i64_t = int64_t;
using u16_t = uint32_t;
using u32_t = uint32_t;
using u64_t = uint64_t;


template<typename T>
SharedPtr<T> createShared(auto&&... args)
{
    return std::make_shared<T>(std::forward<decltype(args)...>(args)...);
}


#define LOG_INFO(...) std::cout << __VA_ARGS__ << '\n'
#define LOG_ERROR(...) std::cout << __VA_ARGS__ << '\n'
#define LOG_WARN(...) std::cout << __VA_ARGS__ << '\n'
#define LOG_FATAL(...) std::cout << __VA_ARGS__ << '\n'

