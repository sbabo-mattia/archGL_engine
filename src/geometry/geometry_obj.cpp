#include "../../include/geometry.h"

namespace mGeometryObject
{

    geometryObjectClass::geometryObjectClass(std::vector<float> vec_vertices) : vertices(vec_vertices)
    {

        initVerticesStruct(false);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);

        OPENGL_LOGI("Created geometry object");
    };

    geometryObjectClass::geometryObjectClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices) : vertices(vec_vertices), indices(indices)
    {

        initVerticesStruct(true);

        /* glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0); */
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);

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

    geometryObjectColoredClass::geometryObjectColoredClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices) : geometryObjectClass(vec_vertices, indices)
    {

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);

        OPENGL_LOGI("Created geometry object");
    };

}