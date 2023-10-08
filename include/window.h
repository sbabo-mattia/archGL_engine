
#pragma once

#include "types.h"

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

        void processInput();

        void processInput(GLFWwindow *window);

        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
        
    };

} // namespace mWindow

