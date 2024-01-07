#pragma once

#include "Details/NullMutex.hpp"

#include <string_view>
#include <string>
#include <chrono>

using string_view_t = std::string_view;

template<typename... Args>
#if __cpp_lib__format >= 202207L
   using format_string_t = std::format_string<Args...>
#else
   using format_string_t = std::string_view;
#endif

namespace sinks
{
   class Sinks;
}

using Log_clock = std::chrono::system_clock;
using memory_buf_t = std::string;

#if defined(NO_ATOMIC_LEVELS)
 using Level_t = null_atomic_int;
#else 
 using Level_t = std::atomic<int>;
#endif //NO_ATOMIC_LEVELS

namespace Level
{

enum LogLevel : int
{
      Trace = 0,
      Debug = 1,
      Info  = 2,
      Warn  = 3,
      Error = 4,
      Fatal = 5,
      Off   = 6
};

} //Namespace Level

struct Source_loc
{
  constexpr Source_loc() = default;
    Source_loc(const char* fileN, int lineN, const char * funcN) 
  : fileName{fileN},
     lineno{lineN},
     funcName{funcN}
   { } 

   const char* fileName{nullptr};
   int lineno = 0;
   const char* funcName{nullptr};
};
