#include "../../include/geometry.h"

namespace mGeometryObject
{

    void geometryObjectClass::vertexPositionAttribute(int size)
    {
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, size * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
    }

    void geometryObjectClass::vertexColorAttribute(int size)
    {
        
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, size * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    void geometryObjectClass::vertexTextureAttribute(int size)
    {
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, size * sizeof(float), (void *)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }

    geometryObjectClass::geometryObjectClass(std::vector<float> vec_vertices, const int&& vertex_size) : vertices(vec_vertices)
    {

        initVerticesStruct(false);

        vertexPositionAttribute(vertex_size);

        OPENGL_LOGI("Created geometry object");
    };

    geometryObjectClass::geometryObjectClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices, const int&& vertex_size) : vertices(vec_vertices), indices(indices)
    {

        initVerticesStruct(true);

        vertexPositionAttribute(vertex_size);
        vertexColorAttribute(vertex_size);

        OPENGL_LOGI("Created geometry object");
    };

    void geometryObjectClass::initVerticesStruct(bool is_indexed = false)
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

        if (is_indexed)
        {
            glGenBuffers(1, &EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
        }
    }

    unsigned int geometryObjectClass::returnVao()
    {
        return VAO;
    }

    void geometryObjectClass::deleteBuffer()
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &EBO);
        glDeleteBuffers(1, &VBO);
    }

}