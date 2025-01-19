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

    window->captureMouse(true);


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

    float dt = 0.0f;
    float lastFrameTook = 0.0f;
    float currentFrameTook = 0.0f;

    while(sceneRunning)
    {
    currentFrameTook = float(SDL_GetTicks()) / 1000;
    dt = currentFrameTook - lastFrameTook;

    // [ Hackish solution : setting window size every render call ]

    SDL_GetWindowSizeInPixels(swindow->getWindow(), &fbw, &fbh);

    scene->resize(fbw, fbh);
    scene->update(dt);
    scene->render();

    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
    scene->move(event, sceneRunning);
    switch(event.type)
    {
    case SDL_EVENT_QUIT:
    sceneRunning = false;
    break;

    case SDL_EVENT_KEY_DOWN:
    switch(event.key.keysym.sym)
    {
    // case SDLK_f:
    // SDL_SetWindowFullscreen(swindow->getWindow(), SDL_TRUE);
    // break;
    case SDLK_2:
    window->captureMouse(false);
    break;
    default:
    break;
    }
    default:
    break;
    }
    }
    SDL_GL_SwapWindow(swindow->getWindow());

    lastFrameTook = currentFrameTook;
    }
    }

    void run(std::unique_ptr<IScene> scene)
    {
    main_loop(std::move(window), std::move(scene));
    }
       
    static std::string parseCLArgs(const std::map<std::string, 
    std::string>& aScene, std::string spec = "None")
    {
    std::string strScene;
    if(spec == "None")
    {
    std::cin >> strScene;
    }
    else
    {
    strScene = spec;
    }
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
