#pragma once

#include <glm/glm.hpp>
#include <SDL3/SDL.h>

class IScene
{
   public:
    IScene()
    : m_width{1280},
      m_height{720},
      m_animating{false}
    {

    }
    virtual ~IScene()
    {

    }

    virtual void update(float dt) = 0;
    virtual void render() = 0; 
    virtual void initScene() = 0;

    void setDiemensions(int w, int h)
    {
    m_width = w;
    m_height = h;
    }
    virtual void resize(int w, int h) = 0; 

    virtual void move(SDL_Event& e, bool& running)
    {

    }

    bool isAnimating() const
    {
    return m_animating;
    }
    void setAnimate(bool b)
    {
    m_animating = b;
    }

   public:
    int m_width;
    int m_height;

    protected:
     bool m_animating;
};
