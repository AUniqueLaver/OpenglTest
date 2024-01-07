#include "LogMsg.hpp"

#include "os.hpp"

namespace uLog 
{

LogMsg::LogMsg(Log_clock::time_point log_time, Source_loc loc,
                                             string_view_t name,
                                             Level::LogLevel log_level,
                                             string_view_t msg)
 :  time{log_time},
    source{loc},
    logger_name{name},
    level{log_level},
    payload{msg}
{

}

LogMsg::LogMsg(Source_loc loc, string_view_t name, Level::LogLevel level,
                                                   string_view_t msg)
 : LogMsg(os::now(), loc, name, level, msg)
{

}
  
}  //namespace uLog
