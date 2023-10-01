
#pragma once

#include "main.h"

namespace mWindow
{

    class windowInitClass
    {
    private:
        GLFWwindow *window;
        int width;
        int height;
        const char *window_name;

    public:
        windowInitClass(int width, int height, const char *window_name);

        int createWindow();

        GLFWwindow *getWindow();

        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

        static void processInput(GLFWwindow *window);
        
    };

} // namespace mWindow

