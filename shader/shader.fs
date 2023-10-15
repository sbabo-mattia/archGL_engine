#version 460 core
  
in vec3 ourColor; // the input variable from the vertex shader (same name and same type)  
out vec4 vertexColor;

void main()
{
    vertexColor = vec4(ourColor, 1.0f);
} 