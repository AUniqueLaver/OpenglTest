#pragma once

#include "ULogger/LogMsg.hpp"
#include "ULogger/Common.hpp"

namespace uLog 
{
  
class Formatter
{
      public:
       virtual ~Formatter() = default;
        virtual void format(const LogMsg& logMsg, memory_buf_t& dest) = 0;
};

}  //namespace uLog
