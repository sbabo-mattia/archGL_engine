#pragma once

#include "types.h"

#include "window.h"
#include "shader.h"
#include <vector>

namespace mEngineBlock
{

    class engineBlockClass
    {
    private:
        GLFWwindow *win;
        bool draw_poly_lines = false;
        std::vector<unsigned int> obj_VAO;
        mShader::mLinkShader::linkingShaderClass* link_shader_program;
        mWindow::windowInitClass window_wrapper;

    public:
        /**
         * @brief Construct a new engine Block Class object
         *
         * @param win
         * @param elements_array
         */
        engineBlockClass(std::vector<unsigned int>& elements_array, mWindow::windowInitClass& window);

        void drawElements();
    };

}