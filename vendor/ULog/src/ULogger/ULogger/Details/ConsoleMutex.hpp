#pragma once

#include "uLogger/Details/NullMutex.hpp"

#include <mutex>

namespace uLog
{

namespace details
{

struct Console_Mutex
{
   using mutex_t = std::mutex;
    static mutex_t& mutex()
      {
     static mutex_t s_mutex;
       return s_mutex;
      }
};

struct Console_NullMutex
{
    using mutex_t = NullMutex;
     static NullMutex& mutex()
       {
       static mutex_t s_mutex;
        return s_mutex;
       }
};

}  //namespace uLog

}
