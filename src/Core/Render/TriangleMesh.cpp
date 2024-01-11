#include "Render/TriangleMesh.hpp"
#include "Core/Log.hpp"

TriangleMesh::TriangleMesh()
 : m_nVerts{0}, m_vao{0}
{

}

TriangleMesh::~TriangleMesh()
{
    deleteBuffers();
}

void TriangleMesh::render()
  //glDrawElements only draws GL_UNSIGNED_BYTE, GL_UNSIGNED_INT,
  //and GL_UNSIGNED_ShORT types.
{
   if(m_vao == 0)
     {
    LOG_WARN("No vao");
      return;
     }

     glBindVertexArray(m_vao);
      glDrawElements(GL_TRIANGLES, m_nVerts, GL_UNSIGNED_INT, NULL);
        glBindVertexArray(0);
}

void TriangleMesh::initBuffers(std::vector<GLuint>* indices,
                               std::vector<GLfloat>* position,
                               std::vector<GLfloat>* normal,
                               std::vector<GLfloat>* texCoords,
                               std::vector<GLfloat>* tangents
                               )
{
         if(!m_buffers.empty())
          deleteBuffers();
   
       if(indices == nullptr || position == nullptr || normal == nullptr)
           {
            LOG_ERROR("Must have indices, position and normals");
                return;
           }

      m_nVerts = static_cast<GLint>(indices->size());

       GLuint idxBuf = 0;
       GLuint posBuf = 0;
       GLuint normBuf = 0;
       GLuint texBuf = 0;
       GLuint tanBuf = 0;

        glGenBuffers(1, &idxBuf);
            m_buffers.push_back(idxBuf);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxBuf);
             glBufferData(GL_ELEMENT_ARRAY_BUFFER,
  // static_cast<long>(indices->size()) * static_cast<long>(sizeof(GLfloat)),
  static_cast<long>(indices->size()) * static_cast<long>(sizeof(GLfloat)),
                          indices->data(),
                          GL_STATIC_DRAW);
          
           glGenBuffers(1, &posBuf);
              m_buffers.push_back(posBuf);
            glBindBuffer(GL_ARRAY_BUFFER, posBuf);
              glBufferData(GL_ARRAY_BUFFER,
static_cast<long>(position->size()) * static_cast<long>(sizeof(GLfloat)),
                           position->data(),
                           GL_STATIC_DRAW);

          glGenBuffers(1, &normBuf);
              m_buffers.push_back(normBuf);
            glBindBuffer(GL_ARRAY_BUFFER, normBuf);
             glBufferData(GL_ARRAY_BUFFER,
    static_cast<long>(normal->size()) * static_cast<long>(sizeof(GLfloat)),
                          normal->data(),
                          GL_STATIC_DRAW);

         if(texCoords != nullptr)
            {
            glGenBuffers(1, &texBuf);
              m_buffers.push_back(texBuf);
             glBindBuffer(GL_ARRAY_BUFFER, texBuf);
              glBufferData(GL_ARRAY_BUFFER,
static_cast<long>(texCoords->size()) * static_cast<long>(sizeof(GLfloat)),
                           texCoords->data(),
                           GL_STATIC_DRAW);
            }

           if(tangents != nullptr)
             {
              glGenBuffers(1, &tanBuf);
                m_buffers.push_back(tanBuf);
               glBindBuffer(GL_ARRAY_BUFFER, tanBuf);
                glBufferData(GL_ARRAY_BUFFER,
 static_cast<long>(tangents->size()) * static_cast<long>(sizeof(GLfloat)),
                              tangents->data(),
                                GL_STATIC_DRAW);
             }

       glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);
    
           glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxBuf);
         
          glBindBuffer(GL_ARRAY_BUFFER, posBuf);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
             glEnableVertexAttribArray(0);
         
            glBindBuffer(GL_ARRAY_BUFFER, normBuf);
               glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
                glEnableVertexAttribArray(1);

            if(texCoords != nullptr)
             {
              glBindBuffer(GL_ARRAY_BUFFER, texBuf);
               glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
                glEnableVertexAttribArray(2);
             }
           
              if(tangents != nullptr)
               {
                 glBindBuffer(GL_ARRAY_BUFFER, tanBuf);
                  glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 0, NULL);
                   glEnableVertexAttribArray(3);
               }
      glBindVertexArray(0);
}
void TriangleMesh::deleteBuffers()
{
       if(m_buffers.size() > 0)
          {
  glDeleteBuffers(static_cast<GLsizei>(m_buffers.size()), m_buffers.data());
            m_buffers.clear();
          }
        
     if(m_vao != 0)
      {
        glDeleteVertexArrays(1, &m_vao);
         m_vao = 0;
      }
}
