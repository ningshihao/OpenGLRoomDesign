#pragma once
#include <GL/glew.h>	 //XXX MacOS Specific
#include <GLFW/glfw3.h> //XXX MacOS Specific
#include <iostream>
#include <string>
#include <fstream>
#include <glm/glm.hpp> //XXX MacOS Specific
#include <glm/gtc/matrix_transform.hpp> //XXX MacOS Specific
#include <glm/gtx/transform.hpp> //XXX MacOS Specific
#include <glm/gtc/type_ptr.hpp> //XXX MacOS Specific
#include <vector>
#include <cmath>
#include <fstream>
#include <time.h>

using namespace std;

class Room {
    private:
        vector<GLfloat> wallVertices;
        
        GLuint shaderProgram;

    public:
        GLuint& getShaderProgram();
        void setup_vao_vbo_ebo();
        void draw();
        void load_shaders(GLuint& shaderProgram);
        void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
        void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
};
