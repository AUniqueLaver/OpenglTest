#pragma once


#include "Base.hpp"

#include <glad/glad.h>
#include <SDL3/SDL.h>

#include <string>

class Window
{
    public:
     struct Settings 
     {
      public:
       std::string title;
       int width = 1280;
       int height = 720;
     };

     Window();
     explicit Window(const Settings& settings);
     ~Window();

     void captureMouse(bool grabbed);

     SDL_Window* getWindow() const 
     {
     return window;
     }
     SDL_GLContext getGLContext() const
     {
     return glContext;
     }

    private:
     SDL_Window* window = nullptr;
     SDL_GLContext glContext = nullptr;
};
