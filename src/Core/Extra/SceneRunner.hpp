#pragma once

#include "Window/Window.hpp"
#include "Core/Log.hpp"
#include "Common.hpp"

class Runner
{
    public:
      Runner(const std::string& title) 
        {
      const unsigned int init_flags{SDL_INIT_EVENTS | SDL_INIT_VIDEO};
     if (SDL_Init(init_flags) != 0)
          {
            LOG_FATAL("Failed to initialize SDL");
          }


      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

      SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
      SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

      SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG); window = std::make_unique<Window>(Window::Settings{title});

       SDL_GetWindowSizeInPixels(window->getWindow(), &fbw, &fbh);

      glClearColor(0.1f,0.1f,0.5f,1.0f);
       }

        ~Runner()
           {
              SDL_Quit();
           }

    void main_loop(std::unique_ptr<Window> swindow, std::unique_ptr<IScene> scene)
       {
      scene->setDiemensions(fbw, fbh);
        scene->initScene();
          scene->resize(fbw, fbh);
 
         while(sceneRunning)
          {
          scene->update(float(SDL_GetTicks()));
           scene->render();

             SDL_Event event;
            while(SDL_PollEvent(&event))
               {
                switch(event.type)
                   {
                    case SDL_EVENT_KEY_DOWN:
                     switch (event.key.keysym.sym)
                      {
                    case SDLK_SPACE:
                            scene->setAnimate(true);
                        break;
                    case SDLK_0:
                          glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                        break;
                    case SDLK_ESCAPE:
                          debug = true;
                           sceneRunning = false;
                         break;
                          default:
                           break;
                      }
                        break;
                    case SDL_EVENT_KEY_UP:
                     switch (event.key.keysym.sym)
                      {
                    case SDLK_SPACE:
                           scene->setAnimate(false);
                        break;
                    case SDLK_0:
                          glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                        break;
                    case SDLK_ESCAPE:
                          debug = true;
                           sceneRunning = false;
                        break;
                          default:
                           break;
                      }
                     break;
                    case SDL_EVENT_QUIT:
                       sceneRunning = false;
                        break;
                  default:
                    break;
                   }
                }
              SDL_GL_SwapWindow(swindow->getWindow());
             }
            }

    void run(std::unique_ptr<IScene> scene)
       {
          main_loop(std::move(window), std::move(scene));
       }
       
 static std::string parseCLArgs(const std::map<std::string, 
                    std::string>& aScene)
     {
       std::string strScene;
        std::cin >> strScene;
         auto it = aScene.find(strScene);
          if(it == aScene.end())
           {
            LOG_ERROR("No scene under such name");
             printf("Availible scenes: \n");
              for(const auto& s : aScene)
                printf(" %11s : %s\n", 
                       s.first.c_str(),
                       s.second.c_str());
               exit(1);
           }
        return strScene;
     }

    private:
       // void printHelp(std::map<std::string,
       //                         std::string>& aScene)
       //   {
       //     printf("Availible scenes: \n");
       //      for(const auto& s : aScene)
       //        printf(" %11s : %s\n", 
       //               s.first.c_str(),
       //               s.second.c_str());
       //   }
    private:

      std::unique_ptr<Window> window = nullptr;

          bool debug = false;
            bool sceneRunning = true;

           int fbw;
             int fbh;
};
