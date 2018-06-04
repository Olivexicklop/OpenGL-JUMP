
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#ifndef camera_h
#define camera_h

class Camera
{
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    
    GLfloat yaw;
    GLfloat pitch;
    
    GLfloat movementSpeed;
    GLfloat turnSpeed;
    
    void update();
    
public:
    Camera();
    Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMovementSpeed, GLfloat startTurnSpeed);
    ~Camera();
    
    void keyControl(bool keys[]);
    void mouseControl(GLfloat xChange, GLfloat yChange);
    
    glm::mat4 calculateViewMatrix();
    
};


#endif /* camera_h */
