#pragma once

#include "uLogger/Formatter/Formatter.hpp"
#include "uLogger/Details/FmtHelper.hpp"
#include "uLogger/os.hpp"

#include <iostream>

namespace uLog 
{
  
class PatternFormatter : public Formatter
{
     public:
       explicit PatternFormatter(std::string eeol = os::default_eol);
        void format(const LogMsg& logMsg, memory_buf_t& dest) override;
     private:
      std::string eol;
};

}  //namespace uLog
