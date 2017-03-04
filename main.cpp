#include "Room.cpp"

const GLuint WIDTH = 800, HEIGHT = 800;
GLFWwindow* window;
int windowWidth, windowHeight;

int initialisation()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
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
   // glfwSetKeyCallback(window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if(glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glfwGetFramebufferSize(window, &windowWidth, &windowHeight);

    glViewport(0, 0, windowWidth, windowHeight);

    glEnable(GL_DEPTH_TEST);

    return 0;
}


int main()
{

    initialisation();
    
    while (!glfwWindowShouldClose(window)) {

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate(); 
    return 0;
}
