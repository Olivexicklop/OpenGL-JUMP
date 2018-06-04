#version 330

layout (location = 0) in vec3 pos;
uniform mat4 Projection;
uniform mat4 model;
uniform mat4 View;

void main()
{
    gl_Position = Projection * View * model * vec4(pos.x,pos.y,pos.z,1.0);
}
