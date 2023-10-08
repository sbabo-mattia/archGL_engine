#pragma once

#include <iostream>
#include <stdlib.h>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#define OPENGL_OK 1
#define OPENGL_ERROR 0

#define WINDOW_NAME "ArchGL Engine"

#define WINDOW_WIDTH 950
#define WINDOW_HEIGHT 450

inline void OPENGL_LOGI(const char *str)
{
    std::cout << "\033[32m" << str << "\033[0m" << std::endl;
}
inline void OPENGL_LOGE(const char *str)
{
    std::cout << "\033[31m" << str << "\033[0m" << std::endl;
}