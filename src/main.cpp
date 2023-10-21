
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
    OPENGL_LOGI("Maximum number of attributes: ", nrAttributes);

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

    std::vector<float> vertices_tr = {
    // positions      
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
     }; 

    std::vector<float> vertices_tr_cl = {
    // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };   


    mGeometryObject::geometryObjectClass triangleObj1 = mGeometryObject::geometryObjectClass(vertices1, indices1, 3);
    mGeometryObject::geometryObjectClass triangleObj2 = mGeometryObject::geometryObjectClass(vertices2, indices2, 3);

    mGeometryObject::geometryObjectClass triangleObj3 = mGeometryObject::geometryObjectClass(vertices_tr, indices2, 6);
    mGeometryObject::geometryObjectClass triangleObj4 = mGeometryObject::geometryObjectClass(vertices_tr_cl, indices2, 6);

    unsigned int VAO1 = triangleObj1.returnVao();
    unsigned int VAO2 = triangleObj2.returnVao();

    unsigned int VAO_tr = triangleObj3.returnVao();
    unsigned int VAO_tr_cl = triangleObj4.returnVao();

    std::vector<unsigned int> VAOs = {VAO_tr_cl};

    mEngineBlock::engineBlockClass engine = mEngineBlock::engineBlockClass(VAOs, windowInit);

    engine.drawElements();

    triangleObj1.deleteBuffer();
    triangleObj2.deleteBuffer();

    glfwTerminate();
    return 0;
}