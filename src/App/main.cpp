#include "Render/Scene.hpp"
#include "Render/TorusScene.hpp"
#include "Extra/SceneRunner.hpp"
#include "Core/Log.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include <fstream>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>

int main()
{
    std::map<std::string, std::string> AvailScenes = 
  {
      {"Scene1", "Basic scene -triangle"},
      {"Torus", "Scene: Torus"},
      {"Scene3", "scene three"}
  };

   // std::string renderScene = Runner::parseCLArgs(AvailScenes);

  std::unique_ptr<IScene> scene;
    // Runner runner(renderScene);
     Runner runner("Default scene");
      // if(renderScene == "Scene1") 
      //   scene = std::make_unique<Scene>();
      // else if(renderScene == "Torus") 
        scene = std::make_unique<TorusScene>();

       runner.run(std::move(scene));
}
