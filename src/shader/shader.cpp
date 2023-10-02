#include "../../include/shader.h"

namespace mShader
{
    namespace mVertexShader
    {
        vertexShaderClass::vertexShaderClass(unsigned int &vertex_shader)
        {
            vertex_shader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex_shader, 1, &vertexShaderSource, NULL);
            glCompileShader(vertex_shader);

            int success;
            char infoLog[512];
            glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                          << infoLog << std::endl;
            }
        }

    }

    namespace mFragmentShader
    {
        fragmentShaderClass::fragmentShaderClass(unsigned int &fragment_shader)
        {
            fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);
            glCompileShader(fragment_shader);

            int success;
            char infoLog[512];
            // check for shader compile errors
            glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                          << infoLog << std::endl;
            }
        }
    }

    namespace mLinkShader
    {
        unsigned int linkShader()
        {

            unsigned int vertex_shader = 0;
            unsigned int fragment_shader = 0;

            mVertexShader::vertexShaderClass vertex_sh = mVertexShader::vertexShaderClass(vertex_shader);
            mFragmentShader::fragmentShaderClass fragment_sh = mFragmentShader::fragmentShaderClass(fragment_shader);

            int success;
            char infoLog[512];

            unsigned int shader_program = glCreateProgram();
            glAttachShader(shader_program, vertex_shader);
            glAttachShader(shader_program, fragment_shader);
            glLinkProgram(shader_program);
            // check for linking errors
            glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                          << infoLog << std::endl;
            }
            glDeleteShader(vertex_shader);
            glDeleteShader(fragment_shader);

            return shader_program;
        }
    }
}