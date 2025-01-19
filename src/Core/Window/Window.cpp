
#include "Window.hpp"
#include "Core/Log.hpp"

#include <iostream>

Window::Window()
{

}

Window::Window(const Settings& settings)
{
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    // constexpr int WindowFlags = SDL_WINDOW_OPENGL | 
    //                             SDL_WINDOW_RESIZABLE |
    //                             SDL_WINDOW_HIGH_PIXEL_DENSITY;
    //
    constexpr int WindowFlags = SDL_WINDOW_OPENGL | 
                          SDL_WINDOW_RESIZABLE;

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
    LOG_FATAL("Failed to load gl function ptrs");
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(glContext);
}

void Window::captureMouse(bool grabbed)
{
    if(grabbed)
    {
    SDL_SetRelativeMouseMode(SDL_TRUE);
    }
    if(!grabbed)
    {
    SDL_SetRelativeMouseMode(SDL_FALSE);
    }
}
