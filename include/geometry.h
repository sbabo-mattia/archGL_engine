#pragma once

#include "types.h"
#include <vector>

namespace mGeometryObject
{
    class geometryObjectClass{

        private:
            std::vector<float> vertices;
            std::vector<unsigned int> indices;
            unsigned int VAO, VBO, EBO;

        public:
            geometryObjectClass(std::vector<float> vec_vertices, std::vector<unsigned int> indices);

            unsigned int returnVao();

            void deleteBuffer();
            
    };
}