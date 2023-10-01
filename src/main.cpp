
#include "../include/main.h"

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    mWindow::windowInitClass windowInit = mWindow::windowInitClass(500, 500, (const char *)"ArchGL");

    GLFWwindow *win = windowInit.getWindow();

    printf("OpenGL version: %s\n", glGetString(GL_VERSION));

    while (!glfwWindowShouldClose(win))
    {
        /* input */
        windowInit.processInput(win);

        /* render */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}