
#include "Render/Scenes/Scene1/Scene.hpp"
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
#include <limits>

int main()
{
    Runner* runner = new Runner("Window");

    runner->run(std::make_unique<Scene>());
}
