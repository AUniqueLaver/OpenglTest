#include "Window.hpp"

#include <iostream>

Window::Window(const Settings& settings)
{
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    constexpr int WindowFlags = SDL_WINDOW_OPENGL | 
                                SDL_WINDOW_RESIZABLE |
                                SDL_WINDOW_HIGH_PIXEL_DENSITY;

      window = SDL_CreateWindow(settings.title.c_str(),
                                settings.width,
                                settings.height,
                                WindowFlags
                                );

        glContext = SDL_GL_CreateContext(window);

          SDL_GL_MakeCurrent(window, glContext);
            SDL_GL_SetSwapInterval(1);

  if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
     {
        std::cerr << "Failed to init glad" << std::endl;
         exit(1);
     }
}

Window::~Window()
{
   SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(glContext);
}
