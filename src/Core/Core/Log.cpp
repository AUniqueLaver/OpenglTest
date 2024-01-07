#include "Log.hpp"

#include "Sinks/StdoutSink.hpp"

Log::Log()
{
   std::vector<std::shared_ptr<sinks::Sinks>> sinks;

    sinks.emplace_back(std::make_shared<sinks::stdout_basic_sink_mt>());
   // sinks[0]->setPattern("%^[%T]");

     m_logger = std::make_shared<Logger>("AppLog",
                                          sinks.begin(),
                                          sinks.end());
       m_logger->setLevel(Level::Trace);
}
