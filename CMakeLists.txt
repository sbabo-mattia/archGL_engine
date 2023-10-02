cmake_minimum_required(VERSION 3.10)

project(OpenGLProj)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp",
                  "src/windowing/*.cpp",
                  "src/geometry/*.cpp",
                  "src/shader/*.cpp"
                  "src/*.c")
add_executable(main ${SOURCES})

include_directories("include/*.h")

find_package(OpenGL REQUIRED)
target_link_libraries(main OpenGL::OpenGL)
target_link_libraries(main glfw3)
target_link_libraries(main GL)





