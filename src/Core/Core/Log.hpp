#pragma once

#include "Logger.hpp"

#include <iostream>
#include <memory>

class Log
{
   public:
      static std::shared_ptr<Logger> logger()
       {
         return get().m_logger;
       }
   private:
     Log();
      static Log& get()
        {
           static Log instance;
          return instance;
        }

   std::shared_ptr<Logger> m_logger;
};

#ifndef DEACTIVATE_LOGGING

#if DEBUG

#define LOG_TRACE(...)  ::Log::logger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)  ::Log::logger()->debug(__VA_ARGS__)

#else

#define LOG_TRACE(...)
#define LOG_DEBUG(...)

#endif //DEBUG

#define LOG_INFO(...) ::Log::logger()->info(__VA_ARGS__)
#define LOG_WARN(...) ::Log::logger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Log::logger()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::Log::logger()->fatal(__VA_ARGS__)

#else

#define LOG_TRACE(...)
#define LOG_DEBUG(...)

#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#define LOG_FATAL(...)

#endif //DEACTIVATE_LOGGING
