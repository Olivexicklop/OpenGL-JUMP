#ifndef Mesh_h
#define Mesh_h

#include <GL/glew.h>

class Mesh
{
    GLuint VAO, VBO;
    GLsizei vertexCount;
public:
    Mesh();
    ~Mesh();
    
    void createMesh(GLfloat vertices[], unsigned int numOfVertices);
    void renderMesh();
    void clearMesh();
};




#endif /* Mesh_h */
