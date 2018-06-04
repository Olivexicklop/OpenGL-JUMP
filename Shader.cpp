#include "Shader.h"

Shader::Shader()
{
    shaderID = 0;
    uniformModel = 0;
    uniformProjection = 0;
    uniformView = 0;
}

void Shader::createFromString(const char* vertexCode, const char* fragmentCode)
{
    compileShader(vertexCode, fragmentCode);
    
}

void Shader::createFromFiles(const char* vertexLocation, const char* fragmentLocation)
{
    std::string vertexString = readFile(vertexLocation);
    std::string fragmentString = readFile(fragmentLocation);
    const char* vertexCode = vertexString.c_str();
    const char* fragmentCode = fragmentString.c_str();
    
    compileShader(vertexCode, fragmentCode);
}

std::string Shader::readFile(const char* fileLocation)
{
    std::string content;
    std::ifstream fileStream(fileLocation, std::ios::in);
    
    if (!fileStream.is_open())
    {
        printf("Failed to read %s",fileLocation);
        return "";
    }
    
    std::string line = "";
    while (!fileStream.eof())
    {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }
    fileStream.close();
    return content;
}

void Shader::compileShader(const char* vertexCode, const char* fragmentCode)
{
    shaderID = glCreateProgram();
    
    if (!shaderID)
    {
        printf("Failed to create shader\n");
        return;
    }
    
    addShader(shaderID,vertexCode,GL_VERTEX_SHADER);
    addShader(shaderID,fragmentCode,GL_FRAGMENT_SHADER);
    
    GLint result = 0;
    GLchar eLog[1024] = {0};
    
    glLinkProgram(shaderID);
    glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
        printf("Error linking program: '%s'\n", eLog);
        return;
    }
    
    uniformProjection = glGetUniformLocation(shaderID, "Projection");
    uniformModel = glGetUniformLocation(shaderID, "model");
    uniformView = glGetUniformLocation(shaderID, "View");
}

GLuint Shader::getProjectionLocation()
{
    return uniformProjection;
}

GLuint Shader::getModelLocation()
{
    return uniformModel;
}

GLuint Shader::getViewLocation()
{
    return uniformView;
}

void Shader::useShader()
{
    glUseProgram(shaderID);
}

void Shader::clearShader()
{
    if (shaderID)
    {
        glDeleteProgram(shaderID);
        shaderID = 0;
    }
    
    uniformModel = 0;
    uniformProjection = 0;
    uniformView = 0;
}

void Shader::addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
    GLuint theShader = glCreateShader(shaderType);
    
    const GLchar* theCode[1];
    theCode[0] = shaderCode;
    
    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);
    
    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);
    
    GLint result = 0;
    GLchar eLog[1024] = {0};
    
    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderInfoLog(theShader, 1024, NULL, eLog);
        fprintf(stderr, "Error compiling the %d shader: '%s'\n", shaderType, eLog);
        return;
    }
    
    glAttachShader(theProgram,theShader);
}

Shader::~Shader()
{
    clearShader();
}
