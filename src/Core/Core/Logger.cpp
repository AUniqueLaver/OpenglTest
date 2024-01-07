#include "Logger.hpp"

#include "Sinks/Sinks.hpp"

void Logger::setLevel(Level::LogLevel level)
{
     m_level.store(level);
}

//Todo: Add tracer
void Logger::log_it(const LogMsg& logMsg,
                                   bool log_enabled,
                                   bool trace_enabled)
{
     if(log_enabled)
       {
           sink_it(logMsg);
       }
      // if(trace_enabled)
      //    {
      //       tracer.push_back(logMsg);
      //    }
}
void Logger::sink_it(const LogMsg& logMsg)
{
     for(auto& sinks_f : sinks)
      {
         if(sinks_f->shouldLog(logMsg.level))
          {
           sinks_f->log(logMsg);
          }
      }
}
