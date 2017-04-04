#include "Room.hpp"

using namespace std;
float camX = 0.0f;
float camY = 0.0f;
Room::Room()
{
    //Uncomment all in this constructor and this will trace a cube.
    //Only the floor and both side walls are kept.
    //X-Y Axis is visible. Z axis is pointed towards the user
    
    ///Face 1 - Face furthest away
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
/*
    ///////Face 2 - The face pointing toward us
    
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
*/
    ///////Face 3 - Left wall
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    ////////Face 4  - Right Wall
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    /////Face5 - Floor
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(-0.5f);
/*
    ///////Face 6 - Ceilling
    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(0.5f);

    room_vertices.push_back(-0.5f);
    room_vertices.push_back(0.5f);
    room_vertices.push_back(-0.5f);
*/

}

void Room::load_shaders()
{
    string vertex_shader_path = "vertex.shader";
    string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_shader_path, ios::in);

    if (VertexShaderStream.is_open()) {
        string Line = "";
        while (getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    } else {
        printf("Impossible to open %s. Are you in the right directory ?\n", vertex_shader_path.c_str());
        getchar();
        exit(-1);
    }

    // Read the Fragment Shader code from the file
    string fragment_shader_path = "fragment.shader";
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_shader_path, std::ios::in);

    if (FragmentShaderStream.is_open()) {
        std::string Line = "";
        while (getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    } else {
        printf("Impossible to open %s. Are you in the right directory?\n", fragment_shader_path.c_str());
        getchar();
        exit(-1);
    }

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(vertexShader, 1, &VertexSourcePointer, NULL);
    glCompileShader(vertexShader);
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(fragmentShader, 1, &FragmentSourcePointer, NULL);
    glCompileShader(fragmentShader);
    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader); //free up memory
    glDeleteShader(fragmentShader);

    glUseProgram(shaderProgram);
}

void Room::setup_buffers() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, room_vertices.size() * sizeof(GLfloat), &room_vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat) ,(GLvoid*) 0);

    glEnableVertexAttribArray(0); 

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    

    glBindVertexArray(0);
}

void Room::draw() {

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, room_vertices.size());
    //cout << "Size " << room_vertices.size()/3;
    //glDrawArrays(GL_LINE_STRIP, 0, room_vertices.size());
    glBindVertexArray(0);
}


void Room::crt() {
        // Get the uniform locations
    GLint transformLoc = glGetUniformLocation(shaderProgram, "model");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
    GLint projLoc = glGetUniformLocation(shaderProgram, "projection");
   
    //View, Model and Projection Matrix
    
    glm::mat4 view;
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 2.0f), 
            glm::vec3(0.0f, 0.0f, 0.0f), 
            glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 model;
    model = glm::rotate(model, camX, glm::vec3(1.0f, 0.0f, 0.0f)) * 
        glm::rotate(model, camY, glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 projection;
        projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);

    // Pass the matrices to the shader
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));  
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

GLuint Room::get_shader() const {
    return shaderProgram;
}
