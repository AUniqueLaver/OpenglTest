#pragma once

#include "uLogger/Formatter/Formatter.hpp"
#include "uLogger/Details/FmtHelper.hpp"
#include "uLogger/os.hpp"

#include <iostream>

namespace uLog 
{

namespace details
{

class FlagFormatter
{
   public:
     virtual ~FlagFormatter() { }
    virtual void format(const LogMsg& msg, const std::tm& time,
                        memory_buf_t& dest) = 0;
      private:
};

class FullFormatter final : public FlagFormatter
{
  public:
    void format(const LogMsg& msg, const std::tm& tm,
                memory_buf_t& dest) override
       {
       auto duration = msg.time.time_since_epoch();
auto secs = std::chrono::duration_cast<std::chrono::seconds>(duration);
       
      if(m_cached_time_stamp != secs || m_cached_tm.size() == 0)
        {
        m_cached_tm.push_back('[');
         appendNumber(tm.tm_year + 1900, m_cached_tm);
        m_cached_tm.push_back('-'); 
            pad2(tm.tm_mon, m_cached_tm);
        m_cached_tm.push_back('-');
            pad2(tm.tm_mday, m_cached_tm);
        m_cached_tm.push_back(' ');

        m_cached_tm.push_back(':');
        m_cached_tm.push_back(' ');

            pad2(tm.tm_hour, m_cached_tm);
        m_cached_tm.push_back(' ');
            pad2(tm.tm_min, m_cached_tm);
        m_cached_tm.push_back(' ');
            pad2(tm.tm_sec, m_cached_tm);

        m_cached_tm.push_back('.');

          m_cached_time_stamp = secs;
        }
       dest.append(m_cached_tm.begin(), m_cached_tm.end());
          
      auto milli = timeFraction<std::chrono::milliseconds>(msg.time);
        pad3(static_cast<uint32_t>(milli.count()), dest);

      dest.push_back(']');

        dest.push_back(' ');

    if(msg.logger_name.size() > 0)
      {
        dest.push_back('[');
      details::appendStringView(msg.logger_name, dest);
        dest.push_back(']');
      }

      dest.push_back(' ');
       
      dest.push_back('[');
  details::appendStringView(level_to_string_view(msg.level), dest);
      dest.push_back(']');
      
      if(!msg.source.empty())
        {
           dest.push_back('[');
        details::appendStringView(msg.source.fileName, dest);
           dest.push_back(':');
        details::appendNumber(msg.source.lineno, dest);
           dest.push_back(']');
        }

        dest.push_back(' ');
          details::appendStringView(msg.payload, dest);
       }

   private:
   std::chrono::seconds m_cached_time_stamp{0};
    memory_buf_t m_cached_tm;
};

}   //namespace details
  
class PatternFormatter final : public Formatter
{
     public:
       explicit PatternFormatter(std::string eeol = os::default_eol,
                       PatternTimeType pt = PatternTimeType::local);
        void format(const LogMsg& logMsg, memory_buf_t& dest) override;
   private:
    std::tm getTime(const LogMsg& msg);
    
     private:
      std::string eol;
    std::vector<std::unique_ptr<details::FlagFormatter>> m_formaters;
       std::tm m_cached_tm;
         PatternTimeType m_pt;
        std::chrono::seconds lastLoggedTime;
};

}  //namespace uLog
