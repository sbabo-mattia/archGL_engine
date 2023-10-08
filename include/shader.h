#pragma once

#include "types.h"

namespace mShader
{
    namespace mVertexShader
    {

        class vertexShaderClass
        {
        private:
            const char *vertexShaderSource = "#version 460 core\n"
                                             "layout (location = 0) in vec3 aPos;\n"
                                             "void main()\n"
                                             "{\n"
                                             "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                             "}\0";

        public:
            vertexShaderClass(unsigned int &vertex_shader);
        };
    }

    namespace mFragmentShader
    {

        class fragmentShaderClass
        {
        private:
            const char *fragmentShaderSource = "#version 460 core\n"
                                               "out vec4 FragColor;\n"
                                               "void main()\n"
                                               "{\n"
                                               "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                               "}\n\0";

        public:
            fragmentShaderClass(unsigned int &fragment_shader);
        };
    }

    namespace mLinkShader
    {

        class linkingShaderClass
        {
        private:
            unsigned int shader_program;

        public:
            linkingShaderClass();
            unsigned int returnShaderProgram();
            void deleteShaderProgram();
        };
    }
}