#include "../../include/geometry.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../../include/stb_image.h"

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

    geometryObjectClass::geometryObjectClass(std::vector<float> vec_vertices, const int &&vertex_size) : vertices(vec_vertices)
    {

        initVerticesStruct(false);

        vertexPositionAttribute(vertex_size);

        OPENGL_LOGD("Created geometry object");
    };

    geometryObjectClass::geometryObjectClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices, const int &&vertex_size) : vertices(vec_vertices), indices(indices)
    {

        initVerticesStruct(true);

        vertexPositionAttribute(vertex_size);
        vertexColorAttribute(vertex_size);

        OPENGL_LOGD("Created geometry object");
    };

    geometryObjectClass::geometryObjectClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices, const char *texture_path, const int &&vertex_size) : vertices(vec_vertices), indices(indices)
    {
        initVerticesStruct(true);

        vertexPositionAttribute(vertex_size);
        vertexColorAttribute(vertex_size);
        vertexTextureAttribute(vertex_size);

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
        unsigned char *data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);

        OPENGL_LOGD("Created geometry object");
    }
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

    size_t geometryObjectClass::indices_size()
    {
        return indices.size();
    }

    unsigned int geometryObjectClass::returnTex()
    {
        return texture;
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