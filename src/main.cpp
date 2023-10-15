
#include "../include/main.h"

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    mWindow::windowInitClass windowInit = mWindow::windowInitClass(WINDOW_WIDTH, WINDOW_HEIGHT, (const char *)WINDOW_NAME);

    OPENGL_LOGI((const char *)glGetString(GL_VERSION));
    OPENGL_LOGI((const char *)glGetString(GL_RENDERER));

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    std::vector<float> vertices1 = {
        0.5f, 0.5f, 0.0f,   // top right
        0.8f, -0.8f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };

    std::vector<unsigned int> indices1 = {
        1, 2, 3 // second Triangle
    };

    std::vector<float> vertices2 = {
        0.5f, 0.5f, 0.0f,   // top right
        0.6f, -0.5f, 0.0f,  // bottom right
        -0.3f, -0.3f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left

    };

    std::vector<unsigned int> indices2 = {
        0, 1, 3, // first Triangle
    };

    mGeometryObject::geometryObjectClass triangleObj1 = mGeometryObject::geometryObjectClass(vertices1, indices1);
    mGeometryObject::geometryObjectClass triangleObj2 = mGeometryObject::geometryObjectClass(vertices2, indices2);

    unsigned int VAO1 = triangleObj1.returnVao();
    unsigned int VAO2 = triangleObj2.returnVao();

    std::vector<unsigned int> vaos = {VAO1, VAO2};

    mEngineBlock::engineBlockClass engine = mEngineBlock::engineBlockClass(vaos, windowInit);

    engine.drawElements();

    triangleObj1.deleteBuffer();
    triangleObj2.deleteBuffer();

    glfwTerminate();
    return 0;
}