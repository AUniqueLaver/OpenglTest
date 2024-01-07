#include "PatternFormatter.hpp"

PatternFormatter::PatternFormatter(std::string eeol)
 : eol{std::move(eeol)}
{

}
      //Todo: Needs formatting, bare minimum done. 
  void PatternFormatter::format(const LogMsg& logMsg, memory_buf_t& dest)
         {
            appendStringView(logMsg.payload, dest);
             appendStringView(eol, dest);
         }
