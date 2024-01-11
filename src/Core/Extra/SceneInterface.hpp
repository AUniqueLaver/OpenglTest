#pragma once

#include <glm/glm.hpp>

class IScene
{
     public:
        IScene() :  animating{false}, width{1280}, height{720} { }
          virtual ~IScene() { }

       virtual void update(float dt) = 0;
        virtual void render() = 0; 
          virtual void initScene() = 0;

           void setDiemensions(int w, int h)
            {
                 width = w;
                 height = h;
            }
              virtual void resize(int w, int h) = 0; 

    bool isAnimating() const { return animating; }
         void setAnimate(bool b) { animating = b; }
     protected:
       glm::mat4 m_model, m_view, m_proj;
        
         bool animating;
     public:
         int width;
          int height;
};
