#include "Log.hpp"

#include "Sinks/StdoutSink.hpp"

Log::Log()
{
  std::vector<std::shared_ptr<uLog::sinks::Sinks>> sinks;

  sinks.emplace_back(std::make_shared<uLog::sinks::stdout_basic_sink_mt>());
   // sinks[0]->setPattern("%^[%T]");

  m_logger = std::make_shared<uLog::Logger>("AppLog",
                                          sinks.begin(),
                                          sinks.end());
      m_logger->setLevel(uLog::Level::Trace);
      // m_logger->setFlushOnl(uLog::Level::Trace);
}
