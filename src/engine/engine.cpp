#include "../../include/engine.h"

namespace mEngineBlock
{
    engineBlockClass::engineBlockClass(std::vector<unsigned int> &elements_array, mWindow::windowInitClass &window) : obj_VAO(elements_array), window_wrapper(window)
    {
        link_shader_program = new mShader::mLinkShader::linkingShaderClass();
    }

    void engineBlockClass::drawElements()
    {

        unsigned int shader_program = link_shader_program->returnShaderProgram();

        while (!glfwWindowShouldClose(window_wrapper.getWindow()))
        {

            window_wrapper.processInput();
            /* code */
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

            glUseProgram(shader_program);

            for (auto &vao_elem : obj_VAO)
            {
                glBindVertexArray(vao_elem); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
                glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
                glBindVertexArray(0);
            }

            glfwSwapBuffers(window_wrapper.getWindow());
            glfwPollEvents();
        }

        link_shader_program->deleteShaderProgram();
    }
}
