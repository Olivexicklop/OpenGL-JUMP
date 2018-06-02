#include "Mesh.h"

Mesh::Mesh()
{
    VAO = 0;
    VBO = 0;
    vertexCount = 0;
}

Mesh::~Mesh()
{
    clearMesh();
}

void Mesh::createMesh(GLfloat vertices[], unsigned int numOfVertices)
{
    vertexCount = numOfVertices;
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    
//    glGenBuffers(1,&IBO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,IBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
    
    
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0])*numOfVertices*3, vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    
    glBindVertexArray(0);
    
}

void Mesh::renderMesh()
{
    glBindVertexArray(VAO);
    //        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    //glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Mesh::clearMesh()
{
    if (VBO)
    {
        glDeleteBuffers(1,&VBO);
        VBO = 0;
    }
    if (VAO)
    {
        glDeleteVertexArrays(1,&VAO);
        VAO = 0;
    }
    vertexCount = 0;
}
