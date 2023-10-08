
#include "../include/main.h"

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    mWindow::windowInitClass windowInit = mWindow::windowInitClass(800, 500, (const char *)"ArchGL");

    printf("OpenGL version: %s\n", glGetString(GL_VERSION));
    printf("OpenGL renderer: %s\n", glGetString(GL_RENDERER));

    /* mShader::mLinkShader::linkingShaderClass link_shader = mShader::mLinkShader::linkingShaderClass();
    unsigned int shader_program = link_shader.returnShaderProgram(); */

    std::vector<float> vertices1 = {
         0.5f,  0.5f, 0.0f,  // top right
         0.8f, -0.8f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    std::vector<unsigned int> indices1 = {
        1, 2, 3  // second Triangle
    };

    std::vector<float> vertices2 = {
         0.5f,  0.5f, 0.0f,  // top right
         0.6f, -0.5f, 0.0f,  // bottom right
        -0.3f, -0.3f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 

    };

    std::vector<unsigned int> indices2 = {
        0, 1, 3, // first Triangle
    };

    mGeometryObject::geometryObjectClass triangleObj1 = mGeometryObject::geometryObjectClass(vertices1, indices1);
    mGeometryObject::geometryObjectClass triangleObj2 = mGeometryObject::geometryObjectClass(vertices2, indices2);

    unsigned int VAO1 = triangleObj1.returnVao();
    unsigned int VAO2 = triangleObj2.returnVao();

    std::vector<unsigned int> vaos = {VAO1, VAO2};

    mEngineBlock::engineBlockClass engine = mEngineBlock::engineBlockClass(vaos, windowInit);

    engine.drawElements();

    /* while (!glfwWindowShouldClose(win))
    {
        // input
        windowInit.processInput(win);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glUseProgram(shader_program);

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glBindVertexArray(VAO1); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        
        glBindVertexArray(VAO2);
        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        // glBindVertexArray(0); // no need to unbind it every time 

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    triangleObj1.deleteBuffer();
    //triangleObj2.deleteBuffer();
    link_shader.deleteShaderProgram(); 
    
    */

    //glfwTerminate();
    return 0;
}