#ifndef window_h
#define window_h

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class window {
    GLFWwindow* mainWindow;
    
    GLint width,height;
    GLint bufferWidth,bufferHeight;
    
public:
    window();
    ~window();
    window(GLint windowWidth, GLint windowHeight);
    
    int initialize();
    
    GLint getBufferWidth() {return bufferWidth;}
    GLint getBufferHeight() {return bufferHeight;}
    
    bool getShouldClose() {return glfwWindowShouldClose(mainWindow);}
    
    void swapBuffers() {glfwSwapBuffers(mainWindow);}
};

#endif /* window_h */
