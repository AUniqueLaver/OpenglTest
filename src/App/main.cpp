#include "Render/Scene.hpp"
#include "Extra/SceneRunner.hpp"
#include "Core/Log.hpp"

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
    // Runner runner("Scene1");
    //  std::unique_ptr<Scene> scene = std::make_unique<Scene>();
    //    runner.run(std::move(scene));
     
   // LOG_TRACE("Log message 1");
  
   LOG_INFO("Log message info");
   LOG_WARN("Log message [warn]");
   LOG_ERROR("Log message [error]");
   LOG_FATAL("Log message [fatal]");

   LOG_TRACE("%s rea fd a2");
   LOG_DEBUG("Log Doop doop 3");
}
