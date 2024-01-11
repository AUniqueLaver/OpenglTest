#pragma once

#include <string>
#include <sstream>
#include <string_view>
#include <map>

using string_view_t = std::string_view;

template<typename T>
std::string to_string(T& val)
{
    std::ostringstream os;
     os << val;
       return os.str();
}
