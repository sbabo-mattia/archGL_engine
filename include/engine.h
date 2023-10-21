#pragma once

#include "types.h"

#include "window.h"
#include "shader.h"
#include "geometry.h"
#include <vector>

namespace mEngineBlock
{

    class engineBlockClass
    {
    private:
        std::vector<mGeometryObject::geometryObjectClass*> obj_GEO;
        mShader::mLinkShader::linkingShaderClass* link_shader_program;
        mWindow::windowInitClass window_wrapper;

    public:
        /**
         * @brief Construct a new engine Block Class object
         *
         * @param win
         * @param elements_array
         */
        engineBlockClass(std::vector<mGeometryObject::geometryObjectClass*>& geometry_array, mWindow::windowInitClass& window);

        void drawElements();
    };

}