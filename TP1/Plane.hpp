#ifndef PLANE_HPP__
#define PLANE_HPP__
#include "GameObject.hpp"

class Plane : public GameObject {
public:
    int resolution;
    int size;
    bool randomHeight;

    // Constructeur de Plane
    Plane() {}

    Plane(std::string name, unsigned int res, unsigned int size, int textureID, const char *texturePath, bool randomHeight=false) {
        this->name = name;
        this->resolution = res;
        this->size = size;
        this->type = PLANE;
        this->textureID = textureID;
        this->texturePath = texturePath;
        this->randomHeight = randomHeight;

        // Init le plan
        init();
        // Generer et charger les buffers
        this->GenerateBuffers();
        // Init la bounding box
        this->initBoundingBox();
    }

    void init()
    {
    indices.clear();
    triangles.clear();
    vertices.clear();
    uvs.clear();

    int nbVertices = resolution * resolution;
    float step = size / (float)resolution;
    float x, y, z, u, v;

    for (int i = 0; i <= resolution; i++)
    {
        for (int j = 0; j <= resolution; j++)
        {
            x = j * step;
            if (randomHeight)
            {
                y = std::max((float)rand() / (RAND_MAX), 0.f);
            }
            else
            {
                y = 0;
            }
            z = i * step;
            u = x / size;
            v = z / size;
            vertices.push_back(glm::vec3(x - size / 2.f, y, z - size / 2.f));
            uvs.push_back(glm::vec2(u, v));
        }
    }

    for (int i = 0; i < resolution; i++)
    {
        for (int j = 0; j < resolution; j++)
        {
            unsigned short bottomLeft = j + i * (resolution + 1);
            unsigned short bottomRight = bottomLeft + 1;
            unsigned short topLeft = bottomLeft + (resolution + 1);
            unsigned short topRight = topLeft + 1;

            triangles.push_back({bottomLeft, bottomRight, topLeft});
            triangles.push_back({bottomRight, topRight, topLeft});

            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
            indices.push_back(topLeft);
            indices.push_back(bottomRight);
            indices.push_back(topRight);
            indices.push_back(topLeft);
        }
    }
        std::cout << "indices size: " << indices.size() << std::endl;
        std::cout << "triangles size: " << triangles.size() << std::endl;
        std::cout << "vertices size: " << vertices.size() << std::endl;
        std::cout << "uvs size: " << uvs.size() << std::endl;
    }

    void computeUV() 
    {
        uv.clear();

        float UvStep = 1.0f / (float)resolution;
        for (int i = 0; i <= resolution; i++)
        {
            for (int j = 0; j <= resolution; j++)
            {
                float u = j * UvStep;
                float v = i * UvStep;
                uv.push_back(glm::vec2(u, v));
            }
        }
    }
};

#endif