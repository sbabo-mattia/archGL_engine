#include "../../include/window.h"

namespace mWindow
{
    
    windowInitClass::windowInitClass(int width = 800, int height = 600, const char *window_name = "OpenGL Window") : width(width), height(height), window_name(window_name)
    {

        if (createWindow() == OPENGL_OK)
            std::cout << "GLFW window created correctly\n";
    }

    int windowInitClass::createWindow()
    {
        window = glfwCreateWindow(width, height, (const char *)window_name, NULL, NULL);

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
            return OPENGL_ERROR;
        }

        glViewport(0, 0, width, height);

        return OPENGL_OK;
    }

    GLFWwindow * windowInitClass::getWindow()
    {
        return window;
    }

    void windowInitClass::framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void windowInitClass::processInput()
    {
        if (glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void windowInitClass::processInput(GLFWwindow *window)
    {
        if (glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    
}
