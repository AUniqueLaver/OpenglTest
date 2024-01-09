#include "uLogger/os.hpp"

namespace uLog 
{
  
namespace os
{

Log_clock::time_point now() noexcept
{
  return Log_clock::now();
}

}   //namepsace os

}  //namespace uLog
