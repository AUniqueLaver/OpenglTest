#pragma once

#include "uLogger/Common.hpp"
#include "uLogger/LogMsg.hpp"

namespace uLog 
{
  
namespace sinks
{

class Sinks
{
    public:
      virtual ~Sinks() = default;
      virtual void log(const LogMsg&) = 0;
      virtual void flush() = 0;

      virtual void setPattern(const std::string& pat) = 0;
      virtual void setFormatter() = 0;

       virtual void setLevel() {}
       Level::LogLevel level() { return Level::Trace; } 
        bool shouldLog(Level::LogLevel level) { return true; } 
     //IMPORTANT: Fix this later.
    private:
       Level_t m_level{Level::Trace};
};

} //namepsace sinks

}  //namespace uLog
