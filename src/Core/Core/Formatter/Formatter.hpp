#pragma once

#include "Core/LogMsg.hpp"
#include "Core/Common.hpp"

class Formatter
{
      public:
       virtual ~Formatter() = default;
        virtual void format(const LogMsg& logMsg, memory_buf_t& dest) = 0;
};
