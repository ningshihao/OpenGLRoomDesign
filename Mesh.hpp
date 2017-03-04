#pragma once
#include <glm/glm.hpp> //XXX MacOS Specific

using namespace std;

struct vertex {
    glm::vec3 position;
    glm::vec2 text_coords;
};

struct texture {
    GLuint;
    string type;
};

class Mesh {
    private:
        GLuint vao, vbo, ebo;
        void mesh_setup();
    public:
        vector<vertex> vertices;
        vector<GLuint> indices;
        vector<texture> textures;
        Mesh(vector<vertex> v, vector<GLuint> i, vector<texture> t): vertices(v), indices(i), textures(t) {};
        void draw(Shader shader);
};
