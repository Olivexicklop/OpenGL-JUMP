#ifndef Shader_h
#define Shader_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>

class Shader
{
    GLuint shaderID, uniformProjection, uniformModel;
    
    void compileShader(const char* vertexCode, const char* fragmentCode);
    void addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
public:
    Shader();
    ~Shader();
    
    void createFromString(const char* vertexCode, const char* fragmentCode);
    void createFromFiles(const char* vertexLocation, const char* fragmentLocation);
    
    std::string readFile(const char* fileLocation);
    GLuint getProjectionLocation();
    GLuint getModelLocation();
    
    void useShader();
    void clearShader();
};

#endif /* Shader_h */
