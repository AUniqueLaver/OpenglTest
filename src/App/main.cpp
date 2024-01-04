#include "Render/Scene.hpp"
#include "Extra/SceneRunner.hpp"

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
    Runner runner("Scene1");
     std::unique_ptr<Scene> scene = std::make_unique<Scene>();
       runner.run(std::move(scene));
}
