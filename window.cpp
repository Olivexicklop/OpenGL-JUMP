#include "window.h"

window::window()
{
    width = 1280;
    height = 720;
    
}

window::~window()
{
    glfwTerminate();
    glfwDestroyWindow(mainWindow);
}

window::window(GLint windowWidth, GLint windowHeight)
{
    width = windowWidth;
    height = windowHeight;
    
}

int window::initialize()
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    mainWindow = glfwCreateWindow(width,height, "JUMP", nullptr, nullptr);
    
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
    
    glfwMakeContextCurrent(mainWindow);
    glewExperimental = GL_TRUE;
    
    glewInit();
    
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, bufferWidth, bufferHeight);
    return 0;
}
