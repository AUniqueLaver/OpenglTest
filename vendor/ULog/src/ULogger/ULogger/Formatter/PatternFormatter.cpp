#include "PatternFormatter.hpp"

namespace uLog 
{
  
PatternFormatter::PatternFormatter(std::string eeol)
 : eol{std::move(eeol)}
{

}
      //Todo: Needs formatting, bare minimum done. 
  void PatternFormatter::format(const LogMsg& logMsg, memory_buf_t& dest)
         {
    details::appendStringView(logMsg.payload, dest);
      details::appendStringView(eol, dest);
         }

}  //namespace uLog
