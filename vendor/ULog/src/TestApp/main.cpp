#include "ULogger/Log.hpp"

#include <fstream>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <future>
#include <mutex>
#include <thread>

int main()
{
  
   LOG_INFO("Log message info");
   LOG_WARN("Log message [warn]");
   LOG_ERROR("Log message [error]");
   LOG_FATAL("Log message [fatal]");

   LOG_TRACE("%s rea fd a2");
   LOG_DEBUG("Log Doop doop 3");
}
