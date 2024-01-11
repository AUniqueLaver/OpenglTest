#pragma once

#include "Render/Drawable.hpp"
#include "Core/Log.hpp"
#include "Common.hpp"

#include <glad/glad.h>

class TriangleMesh : public Drawable
{
    public:
     TriangleMesh();
      virtual ~TriangleMesh();
       virtual void render() override;
     protected:
         virtual void initBuffers(std::vector<GLuint>* indices,
                                  std::vector<GLfloat>* position,
                                  std::vector<GLfloat>* normal,
                                  std::vector<GLfloat>* texCoords = nullptr,
                                  std::vector<GLfloat>* tangent = nullptr);
          virtual void deleteBuffers();

            GLuint getIdxBuf() const { return m_buffers[0]; }
             GLuint getPosBuf() const { return m_buffers[1]; }
              GLuint getNormBuf() const { return m_buffers[2]; }
   GLuint getTexBuf() const 
             { 
          if(m_buffers.size() < 3) 
             return m_buffers[3];

            LOG_WARN("Returning 0");
               return 0;
             }
    GLuint getTanBuf() const
             { 
              if(m_buffers.size() < 3) 
                 return m_buffers[4];

            LOG_WARN("Returning 0");
               return 0;
             }
            
      protected:
         GLint m_nVerts;
           GLuint m_vao;
            std::vector<GLuint> m_buffers;
        private:
};
