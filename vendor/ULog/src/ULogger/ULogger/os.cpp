#include "uLogger/os.hpp"

namespace uLog 
{
  
namespace os
{

Log_clock::time_point now() noexcept
{
  return Log_clock::now();
}

std::tm localTime(const std::time_t& tt)
{
  std::tm tm;
    localtime_r(&tt, &tm);
   return tm;
}

std::tm localTime()
{
    std::time_t tt = time(nullptr);
     return localTime(tt);
}

std::tm gmTime(const time_t& tt)
{
     std::tm tm;
       gmtime_r(&tt, &tm);
   return tm;
}

std::tm gmTime()
{
     std::time_t tt = time(nullptr);
      return gmTime(tt);
}

}   //namepsace os

}  //namespace uLog
