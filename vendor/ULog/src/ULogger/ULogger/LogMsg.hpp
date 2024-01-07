#pragma once

#include "Common.hpp"

namespace uLog 
{

struct LogMsg
{
     public:
       LogMsg() = default;
      LogMsg(Log_clock::time_point log_time, Source_loc loc, string_view_t name, Level::LogLevel level, string_view_t msg);
      LogMsg(Source_loc loc, string_view_t name, Level::LogLevel log_level, string_view_t msg);
      LogMsg(const LogMsg& rhs) = default;
      LogMsg& operator=(const LogMsg& rhs) = default;
     
     public:
       Log_clock::time_point time;
       Source_loc source;
       string_view_t logger_name;
       Level::LogLevel level{Level::LogLevel::Off};
       // size_t thread_id{0};
     
       string_view_t payload;
};

}  //namespace uLog
