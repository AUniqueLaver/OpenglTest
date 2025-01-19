#include "PatternFormatter.hpp"

namespace uLog 
{
  
PatternFormatter::PatternFormatter(std::string eeol,
                                   PatternTimeType pt)
 : eol{std::move(eeol)},
   m_pt{pt},
   lastLoggedTime{0}
{
    std::memset(&m_cached_tm, 0, sizeof(m_cached_tm));
    m_formaters.push_back(std::make_unique<details::FullFormatter>());
}

  void PatternFormatter::format(const LogMsg& logMsg, memory_buf_t& dest)
         {
const 
  auto
 secs = std::chrono::duration_cast<std::chrono::seconds>
    (logMsg.time.time_since_epoch());
     if(lastLoggedTime != secs)
         {
          m_cached_tm = getTime(logMsg);
         }
   
              for(auto& s : m_formaters)
               {
          s->format(logMsg, m_cached_tm, dest);
               }
             details::appendStringView(eol, dest);
         }

std::tm PatternFormatter::getTime(const LogMsg& msg)
 {
       if(m_pt == PatternTimeType::local)
    return os::localTime(Log_clock::to_time_t(msg.time));

      return os::gmTime(Log_clock::to_time_t(msg.time));
 }

}  //namespace uLog
