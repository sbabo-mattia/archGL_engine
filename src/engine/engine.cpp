#include "../../include/engine.h"

namespace mEngineBlock
{
    engineBlockClass::engineBlockClass(std::vector<unsigned int> &elements_array, mWindow::windowInitClass& window) : obj_VAO(elements_array), window_wrapper(window)
    {
               
    }

    void engineBlockClass::drawElements()
    {

        while (!glfwWindowShouldClose(window_wrapper.getWindow()))
        {

            window_wrapper.processInput();
            /* code */
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window_wrapper.getWindow());
            glfwPollEvents();
        }
    }
}
