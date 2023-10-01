The purpose of this repository is for running OpenGL with Wayland display server protocol.

# Requirements
You should have GLFW and its dependencies installed.

    sudo yay -S cmake libglu1-mesa-dev glfw-wayland

Or install glfw from the official repository

    git clone https://github.com/glfw/glfw.git
    cd glfw
    cmake -G "Unix Makefiles"  
    make  
    sudo make install