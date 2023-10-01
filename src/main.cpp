

#include "../include/main.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

class windowInitClass
{
    private:
        GLFWwindow* window;
        int width;
        int height;
        const char* window_name;
    
    public:
        windowInitClass(int width = 800, int height = 600, const char* window_name = "openGL") : width(width), height(height), window_name(window_name){
            
            if(createWindow() == OPENGL_OK)
                std::cout<<"GLFW window created correctly\n";
        }

        int createWindow()
        {
            window = glfwCreateWindow(width, height, (const char*)window_name, NULL, NULL);
            
            if (window == NULL)
            {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return OPENGL_ERROR;
            }

            glfwMakeContextCurrent(window);

            glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cout << "Failed to initialize GLAD" << std::endl;
                return -1;
            }    

            glViewport(0, 0, width, height);
            
            return OPENGL_OK;
        }

        GLFWwindow* getWindow()
        {
            return window;
        }

};

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    
    windowInitClass windowInit = windowInitClass(500, 500);

    GLFWwindow* win = windowInit.getWindow();

    printf("OpenGL version: %s\n", glGetString(GL_VERSION));

    while(!glfwWindowShouldClose(win))
    {
        // input
        processInput(win);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(win);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}