#include "Common.hpp"

namespace uLog
{

static string_view_t log_names[] = ULOG_NAMES;

string_view_t level_to_string_view(Level::LogLevel level)
{
       return log_names[level];
}

}    //namespace uLog
