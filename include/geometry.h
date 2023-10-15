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
        geometryObjectClass(std::vector<float> vec_vertices);
        geometryObjectClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices);

        void initVerticesStruct(bool is_indexed);
        unsigned int returnVao();

        void deleteBuffer();
    };

    class geometryObjectColoredClass : public geometryObjectClass
    {
    private:
    public:
        geometryObjectColoredClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices);
        ~geometryObjectColoredClass();
    };

}