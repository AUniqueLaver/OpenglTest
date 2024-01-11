#pragma once

#include "TriangleMesh.hpp"
#include "Common.hpp"

class Torus : public TriangleMesh
{
  public:
    Torus();
     void initTorus(GLfloat innerRad,
                       GLfloat outerRad,
                       GLuint nsides,
                       GLuint nrings);
  private:
};
