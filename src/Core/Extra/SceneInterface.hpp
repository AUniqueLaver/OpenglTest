#pragma once

#include <glm/glm.hpp>

class SceneI
{
     public:
        SceneI() :  animating{true}, width{1280}, height{720} { }
          virtual ~SceneI() { }

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
       glm::mat4 model, view, proj;
        
         bool animating = true;
     public:
         int width;
          int height;
};
