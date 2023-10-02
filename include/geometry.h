#pragma once

#include "main.h"
#include <vector>



namespace mGeometryObject
{

    

    class geometryObjectClass{

        private:
            std::vector<float> vertices;
            unsigned int VBO;

        public:
            unsigned int VAO;
            geometryObjectClass(std::vector<float> vec_vertices);
            
    };
}