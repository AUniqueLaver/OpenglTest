#pragma once

#include "Core/Formatter/Formatter.hpp"
#include "Core/Details/FmtHelper.hpp"
#include "Core/os.hpp"

#include <iostream>

class PatternFormatter : public Formatter
{
     public:
       explicit PatternFormatter(std::string eeol = os::default_eol);
        void format(const LogMsg& logMsg, memory_buf_t& dest) override;
     private:
      std::string eol;
};
