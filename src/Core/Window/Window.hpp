#pragma once

#include <glad/glad.h>
#include <SDL3/SDL.h>

#include <string>

class Window
{
    public:
      struct Settings 
       {
       std::string title;
         int width = 1280;
         int height = 720;
       };

      explicit Window(const Settings& settings);
       ~Window();

     SDL_Window* getWindow() const { return window; }
      SDL_GLContext getGLContext() const { return glContext; }
    private:
     SDL_Window* window = nullptr;
      SDL_GLContext glContext = nullptr;
};
