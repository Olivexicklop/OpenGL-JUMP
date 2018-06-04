#ifndef window_h
#define window_h

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class window {
    GLFWwindow* mainWindow;
    
    GLint width,height;
    GLint bufferWidth,bufferHeight;
    
    bool keys[1024];
    
    GLfloat lastX, lastY;
    GLfloat xChange, yChange;
    bool mouseFirstMoved;
    
    void createCallbacks();
    static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
    static void handleMouse(GLFWwindow* window, double xPos, double yPos);

public:
    window();
    ~window();
    window(GLint windowWidth, GLint windowHeight);
    
    int initialize();
    
    GLint getBufferWidth() {return bufferWidth;}
    GLint getBufferHeight() {return bufferHeight;}
    
    bool getShouldClose() {return glfwWindowShouldClose(mainWindow);}
    bool* getKeys() {return keys; }
    GLfloat getXChange();
    GLfloat getYChange();
    
    void swapBuffers() {glfwSwapBuffers(mainWindow);}
    
};

#endif /* window_h */
