
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
    printf("OpenGL renderer: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL shader: %s\n", glGetString(GL_SHADER_COMPILER));

    unsigned int shader_program = mShader::mLinkShader::linkShader();

    std::vector<float> vertices = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    mGeometryObject::geometryObjectClass triangleObj = mGeometryObject::geometryObjectClass(vertices);

    unsigned int VAO = triangleObj.VAO;

    while (!glfwWindowShouldClose(win))
    {
        /* input */
        windowInit.processInput(win);

        /* render */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 6);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}