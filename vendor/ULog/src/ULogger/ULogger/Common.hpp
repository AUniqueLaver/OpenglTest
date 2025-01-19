#pragma once

#include "Details/NullMutex.hpp"

#include <string_view>
#include <string>
#include <chrono>
#include <format>
#include <utility>

namespace uLog 
{

using string_view_t = std::string_view;

template<typename... Args>
// #if __cpp_lib__format >= 202207L
   using format_string_t = std::format_string<Args...>;
// #else
//    using format_string_t = std::string_view;
// #endif

namespace sinks
{
   class Sinks;
}

enum class PatternTimeType
{
     utc,
     local
};

namespace fmt = std;

using Log_clock = std::chrono::system_clock;
using memory_buf_t = std::string;

#if defined(NO_ATOMIC_LEVELS)
 using Level_t = null_atomic_int;
#else 
 using Level_t = std::atomic<int>;
#endif //NO_ATOMIC_LEVELS

#define ULOG_TRACE 0
#define ULOG_DEBUG 1
#define ULOG_INFO  2
#define ULOG_WARN  3
#define ULOG_ERROR 4
#define ULOG_FATAL 5
#define ULOG_OFF   6

namespace Level
{

enum LogLevel : int
{
      Trace = ULOG_TRACE,
      Debug = ULOG_DEBUG,
      Info  = ULOG_INFO,
      Warn  = ULOG_WARN,
      Error = ULOG_ERROR,
      Fatal = ULOG_FATAL,
      Off   = ULOG_OFF
};

#define ULOG_TRACE_NAME string_view_t("trace", 5)
#define ULOG_DEBUG_NAME string_view_t("debug", 5)
#define ULOG_INFO_NAME  string_view_t("info", 4)
#define ULOG_WARN_NAME  string_view_t("warn", 4)
#define ULOG_ERROR_NAME string_view_t("error", 5)
#define ULOG_FATAL_NAME string_view_t("fatal", 5)
#define ULOG_OFF_NAME   string_view_t("off", 3)

#define ULOG_NAMES { \
  ULOG_TRACE_NAME, ULOG_DEBUG_NAME, ULOG_INFO_NAME, ULOG_WARN_NAME, \
  ULOG_ERROR_NAME, ULOG_FATAL_NAME, ULOG_OFF_NAME              \
                   };

} //Namespace Level

string_view_t level_to_string_view(Level::LogLevel level);

struct Source_loc
{
  constexpr Source_loc() = default;
    Source_loc(const char* fileN, int lineN, const char * funcN) 
  : fileName{fileN},
     lineno{lineN},
     funcName{funcN}
   { } 

    constexpr bool empty() const { return lineno == 0; }

   const char* fileName{nullptr};
   int lineno = 0;
   const char* funcName{nullptr};
};

namespace details
{
   template<typename T, typename... Args>
    std::basic_string_view<T> to_string_view
     (std::basic_format_string<T, Args...> fmt)
       {
           return fmt.get();
       }
}     //namespace details

}  //namespace uLog
