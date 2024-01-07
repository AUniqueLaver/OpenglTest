#pragma once

#include "Core/Common.hpp"
#include "Core/LogMsg.hpp"
#include "Core/BackTracer.hpp"

#include <iostream>

class Logger
{
    public:
      template<typename It>
         Logger(std::string name, It first, It last)
          : m_name{name},
            sinks{first, last}
           { }

     // template<typename T, typename... Args>
     //   void log(Level::LogLevel level, format_string_t<Args...> fmt, Args &&...args)
     // {
     //
     // }

       void log(Source_loc loc, Level::LogLevel level, string_view_t msg)
         {
             LogMsg logmsg(loc, m_name, level, msg);
         }

        void log(Level::LogLevel level, string_view_t msg)
          {
            bool log_enabled = should_log(level);
            bool trace_enabled = should_trace();
              if(!log_enabled && !trace_enabled)
                return;

             LogMsg logMsg(Source_loc{}, m_name, level, msg);
              log_it(logMsg, log_enabled, trace_enabled);
          }

      template<typename T>
       void trace(const T& msg)
        {
            log(Level::LogLevel::Trace, msg);
        }
      template<typename T>
        void debug(const T& msg)
         {
            log(Level::LogLevel::Debug, msg);
         }
      template<typename T>
        void info(const T& msg)
         {
            log(Level::LogLevel::Info, msg);
         }
      template<typename T>
        void warn(const T& msg)
        {
            log(Level::LogLevel::Warn, msg);
        }
      template<typename T>
        void error(const T& msg)
        {
            log(Level::LogLevel::Error, msg);
        }
      template<typename T>
         void fatal(const T& msg)
        {
            log(Level::LogLevel::Fatal, msg);
        }

        void setLevel(Level::LogLevel level);
     protected:
       void log_it(const LogMsg& logMsg,
                                   bool log_enabled,
                                   bool trace_enabled);
      void sink_it(const LogMsg& logMsg);


       bool should_log(Level::LogLevel level) const
         {
            return level >= m_level.load();
         }
      bool should_trace() const { return m_tracer.enabled(); }
     protected:
      std::string m_name;
      std::vector<std::shared_ptr<sinks::Sinks>> sinks;
      Level_t m_level{Level::Info};
      Back_tracer m_tracer;
};
