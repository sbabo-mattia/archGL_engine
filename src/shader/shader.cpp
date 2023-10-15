#include "../../include/shader.h"

namespace mShader
{
    namespace mVertexShader
    {
        vertexShaderClass::vertexShaderClass(unsigned int &vertex_shader, const char* vertex_shader_path)
        {

            std::string shader_code;
            std::ifstream shader_file;

            shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            try
            {
                shader_file.open(vertex_shader_path);
                std::stringstream vshader_stream;

                vshader_stream << shader_file.rdbuf();

                shader_file.close();

                shader_code = vshader_stream.str();
                vertexShaderSource = shader_code.c_str();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                OPENGL_LOGE("ERROR OPENING VERTEX SHADER FILE");
            }
            
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
        fragmentShaderClass::fragmentShaderClass(unsigned int &fragment_shader, const char* fragment_shader_path)
        {

            std::string shader_code;
            std::ifstream shader_file;

            shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            try
            {
                shader_file.open(fragment_shader_path);
                std::stringstream vshader_stream;

                vshader_stream << shader_file.rdbuf();

                shader_file.close();

                shader_code = vshader_stream.str();
                fragmentShaderSource = shader_code.c_str();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                OPENGL_LOGE("ERROR OPENING FRAGMENT SHADER FILE");
            }

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
        linkingShaderClass::linkingShaderClass()
        {

            unsigned int vertex_shader = 0;
            unsigned int fragment_shader = 0;

            mVertexShader::vertexShaderClass vertex_sh = mVertexShader::vertexShaderClass(vertex_shader, "../shader/shader.vs");
            mFragmentShader::fragmentShaderClass fragment_sh = mFragmentShader::fragmentShaderClass(fragment_shader, "../shader/shader.fs");

            int success;
            char infoLog[512];

            shader_program = glCreateProgram();
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

            OPENGL_LOGI("Created linking shader program");
        }

        unsigned int linkingShaderClass::returnShaderProgram()
        {
            return shader_program;
        }

        void linkingShaderClass::deleteShaderProgram()
        {
            glDeleteProgram(shader_program);
        }
    }
}