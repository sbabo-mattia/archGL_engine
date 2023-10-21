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


inline void OPENGL_LOGI()
{
    std::cout << "\033[32m" << ' ' << "\033[0m"<< std::endl;
}

template <typename T, typename... args>
inline void OPENGL_LOGI(const T &str, const args &...other)
{
    std::cout << "\033[32m" << str << "\033[0m";
    OPENGL_LOGI(other...);
}

inline void OPENGL_LOGD()
{
    std::cout <<  "\033[1;33m" << ' ' << "\033[0m" << std::endl;
}

template <typename T, typename... args>
inline void OPENGL_LOGD(const T &str, const args &...other)
{
    std::cout << "\033[1;33m" << str << "\033[0m" ;
    OPENGL_LOGI(other...);
}

inline void OPENGL_LOGE()
{
    std::cout <<  "\033[31m" << ' ' << "\033[0m" << std::endl;
}

template <typename T, typename... args>
inline void OPENGL_LOGE(const T &str, const args &...other)
{
    std::cout << "\033[31m" << str << "\033[0m" ;
    OPENGL_LOGI(other...);
}