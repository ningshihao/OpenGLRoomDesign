#pragma once
#include <GL/glew.h>	 //XXX MacOS Specific
#include <GLFW/glfw3.h> //XXX MacOS Specific
#include <glm/glm.hpp> //XXX MacOS Specific
#include <glm/gtc/matrix_transform.hpp> //XXX MacOS Specific
#include <glm/gtc/type_ptr.hpp> //XXX MacOS Specific

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const GLuint WIDTH = 800, HEIGHT = 800;
extern float camX;
extern float camY;
const float CAMERAINCREMENT = 0.1;

    
class Room {
    private:
        vector<GLfloat> room_vertices;
        GLuint shaderProgram, vao, vbo;

    public:
        Room();
        void setup_buffers();
        void draw();
        void load_shaders();
        void crt();
        GLuint get_shader() const;
};
