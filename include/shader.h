#pragma once

#include "types.h"

#include <string>
#include <fstream>
#include <sstream>

namespace mShader
{
    namespace mVertexShader
    {

        class vertexShaderClass
        {
        private:
            const char *vertexShaderSource;

        public:
            vertexShaderClass(unsigned int &vertex_shader, const char* vertex_shader_path);
        };
    }

    namespace mFragmentShader
    {

        class fragmentShaderClass
        {
        private:
            const char *fragmentShaderSource;

        public:
            fragmentShaderClass(unsigned int &fragment_shader, const char* fragment_shader_path);
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