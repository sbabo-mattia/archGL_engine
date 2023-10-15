#pragma once

#include "types.h"
#include <vector>

namespace mGeometryObject
{

    class geometryObjectClass
    {

    private:
        std::vector<float> vertices;
        std::vector<unsigned int> indices;

        unsigned int VAO, VBO, EBO;

    public:
        typedef void (geometryObjectClass::*funcAttribute)();

        geometryObjectClass(std::vector<float> vec_vertices, const int&& vertex_size);
        geometryObjectClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices, const int&& vertex_size);

        void initVerticesStruct(bool is_indexed);

        void vertexPositionAttribute(int size);
        void vertexColorAttribute(int size);
        void vertexTextureAttribute(int size);

        unsigned int returnVao();

        void deleteBuffer();
    };

}