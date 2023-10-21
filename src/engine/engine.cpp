#include "../../include/engine.h"

namespace mEngineBlock
{
    engineBlockClass::engineBlockClass(std::vector<mGeometryObject::geometryObjectClass*> &geometry_array, mWindow::windowInitClass &window) : obj_GEO(geometry_array), window_wrapper(window)
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

            for (auto &elem : obj_GEO)
            {
                glBindVertexArray(elem->returnVao()); 

                if (elem->returnTex())
                {
                    glBindTexture(GL_TEXTURE_2D, elem->returnTex());
                }
                // glDrawArrays(GL_TRIANGLES, 0 , 3); // if EBO is not used
                glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(elem->indices_size()), GL_UNSIGNED_INT, 0);
                glBindVertexArray(0);
            }

            glfwSwapBuffers(window_wrapper.getWindow());
            glfwPollEvents();
        }

        link_shader_program->deleteShaderProgram();
    }
}
