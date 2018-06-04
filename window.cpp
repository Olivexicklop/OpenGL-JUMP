#include "window.h"

window::window()
{
    width = 1280;
    height = 720;
    
    for (size_t i=0; i<1024; i++)
    {
        keys[i] = 0;
        
    }
    
    mouseFirstMoved = true;
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
    
    createCallbacks();
    glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, bufferWidth, bufferHeight);
    
    glfwSetWindowUserPointer(mainWindow, this);
    return 0;
}

void window::createCallbacks()
{
    glfwSetKeyCallback(mainWindow, handleKeys);
    glfwSetCursorPosCallback(mainWindow, handleMouse);
}


void window::handleKeys(GLFWwindow* window, int key, int code, int action, int mode)
{
    class window* theWindow = static_cast<class window*>(glfwGetWindowUserPointer(window));
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    
    if (key >= 0 && key <= 1024)
    {
        if (action == GLFW_PRESS)
        {
            theWindow->keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            theWindow->keys[key] = false;
        }
    }
}

void window::handleMouse(GLFWwindow* window, double xPos, double yPos)
{
    class window* theWindow = static_cast<class window*>(glfwGetWindowUserPointer(window));
    
    if (theWindow->mouseFirstMoved)
    {
        theWindow->lastX = xPos;
        theWindow->lastY = yPos;
        theWindow->mouseFirstMoved = false;
    }
    
    theWindow->xChange = xPos - theWindow->lastX;
    theWindow->yChange = theWindow->lastY - yPos;
    
    theWindow->lastX = xPos;
    theWindow->lastY = yPos;
    
    
}

GLfloat window::getXChange()
{
    GLfloat theChange = xChange;
    xChange = 0.0f;
    return theChange;
}

GLfloat window::getYChange()
{
    GLfloat theChange = yChange;
    yChange = 0.0f;
    return theChange;
}














