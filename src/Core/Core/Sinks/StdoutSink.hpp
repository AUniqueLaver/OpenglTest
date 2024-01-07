#pragma once

#include "Sinks.hpp"

#include "Core/Formatter/PatternFormatter.hpp"
#include "Core/Details/ConsoleMutex.hpp"
#include "Core/Common.hpp"

#include <cstdio>

namespace sinks
{

template<typename ConsoleMutex>
class StdoutSinkBase : public Sinks
{
   public:
     using mutex_t = typename ConsoleMutex::mutex_t;

    explicit StdoutSinkBase(FILE* fname)
       : m_mutex{ConsoleMutex::mutex()},
         m_file{fname},
         m_formatter{std::make_unique<PatternFormatter>()}
      {

      }

     ~StdoutSinkBase() override = default;

      void log(const LogMsg& logMsg) override
       {
      std::lock_guard<mutex_t> lock(m_mutex);
       memory_buf_t formmated;
        m_formatter->format(logMsg, formmated);
          ::fwrite(formmated.data(), sizeof(char),
                   formmated.size(), m_file);
          ::fflush(m_file);
       }
      void flush() override
       {
    //Todo: Implement this 
       }
      void setPattern(const std::string& pat) override
       {
      std::lock_guard<mutex_t> lock(m_mutex);
         m_formatter = std::make_unique<PatternFormatter>();
    //Todo: Fix this
       }
      void setFormatter() override
       {
    //Todo: Implement this 
       }

   protected:
     mutex_t& m_mutex;
     FILE* m_file;
      std::unique_ptr<Formatter> m_formatter;
   private:
     
};

template<typename ConsoleMutex>
class Stdout_Sink : public StdoutSinkBase<ConsoleMutex>
{
     public:
      Stdout_Sink()
       : StdoutSinkBase<ConsoleMutex>(stdout)
        {

        }
};

using stdout_basic_sink_mt = Stdout_Sink<Console_Mutex>;
using stdout_basic_sink_st = Stdout_Sink<Console_NullMutex>;

}    //namespace sinks
