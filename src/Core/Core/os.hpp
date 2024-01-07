#pragma once

#include "Common.hpp"

namespace os
{
  #if !defined(LOG_EOL)
    #ifdef _WIN32
#define LOG_EOL "\r\n"
    #else
#define LOG_EOL "\n"
    #endif //_WIN32
 #endif   

   constexpr static const char* default_eol = LOG_EOL;

      Log_clock::time_point now() noexcept;
}  //os
