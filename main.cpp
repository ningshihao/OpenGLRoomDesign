#include "Room.hpp"

GLFWwindow* window;
int windowWidth, windowHeight;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if(key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        camX += CAMERAINCREMENT;
    else if(key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        camX -= CAMERAINCREMENT;
    else if(key == GLFW_KEY_UP && action == GLFW_PRESS) 
        camY += CAMERAINCREMENT;
    else if(key == GLFW_KEY_DOWN && action == GLFW_PRESS) 
        camY -= CAMERAINCREMENT;
}

int init()
{
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //XXX MacOS Specific
    // Create a GLFWwindow object that we can use for GLFW's functions
    window = glfwCreateWindow(WIDTH, HEIGHT, "The Room", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // Set the required callback functions(Enter and mouse)

    //   glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetKeyCallback(window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extension
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if(glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glfwGetFramebufferSize(window, &windowWidth, &windowHeight);

    glViewport(0, 0, windowWidth, windowHeight);

    glEnable(GL_DEPTH_TEST);
    
    //Non-boiler plate stuff. Room generation
    Room living_room = Room::Room();
    living_room.load_shaders();
    living_room.setup_buffers();

    while (!glfwWindowShouldClose(window)) {     
        glfwPollEvents();
        glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

       living_room.crt();   

        glUseProgram(living_room.get_shader());
        living_room.draw();

        glfwSwapBuffers(window);
    }
    glfwTerminate(); 

    return 0;
}


int main()
{
    init();

    //I have no clue why placing the block below in initialisation() render the cube.
    /*Room living_room = Room::Room();
    living_room.load_shaders();
    living_room.setup_buffers();

    while (!glfwWindowShouldClose(window)) {     
        glfwPollEvents();
        glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        living_room.get_camera();
        living_room.get_perspectives();   

        glUseProgram(living_room.get_shader());
        living_room.draw();

        glfwSwapBuffers(window);
    }
    glfwTerminate(); */
}
