#ifndef SPHERE_HPP__
#define SPHERE_HPP__

#include "variables.hpp"
#include "GameObject.hpp"

class Sphere : public GameObject {
public:
    int resolution;
    float radius;

    // CONSTRUCTOR
    Sphere(std::string name, unsigned int res, unsigned int rad, int textureID = 0, const char *texturePath = "") {
        this->name = name;
        this->textureID = textureID;
        this->texturePath = texturePath;
        this->resolution = res;
        this->radius = rad;
        this->type = SPHERE;

        // Init
        init();
        computeUV();
        //  Generer et charger les buffers
        this->GenerateBuffers();
        // Init la bounding box
        this->initBoundingBox();
        // move(window, deltaTime);
    }

    void init()
    {
        indices.clear();
        vertices.clear();

        for (int i = 0; i <= resolution; ++i) {
            float theta = M_PI * (i / (float)resolution);
            float sin_theta = sin(theta);
            float cos_theta = cos(theta);

            for (int j = 0; j <= resolution; ++j) {
                float phi = 2 * M_PI * (j / (float)resolution);
                float sin_phi = sin(phi);
                float cos_phi = cos(phi);

                glm::vec3 vertex = glm::vec3(cos_phi * sin_theta, cos_theta, sin_phi * sin_theta);
                vertices.push_back(vertex * radius);
            }
        }

        for (int i = 0; i < resolution; ++i) {
            for (int j = 0; j < resolution; ++j) {
                int i1 = i * (resolution + 1) + j;
                int i2 = i1 + 1;
                int i3 = (i + 1) * (resolution + 1) + j;
                int i4 = i3 + 1;

                indices.push_back(i1);
                indices.push_back(i3);
                indices.push_back(i2);

                indices.push_back(i2);
                indices.push_back(i3);
                indices.push_back(i4);
            }
        }
    };

    void computeUV()
    {
        uvs.clear();
        float uv_step = 1.0f / static_cast<float>(resolution);
        for (int i = 0; i < resolution + 1; i++)
        {
            for (int j = 0; j < resolution + 1; j++)
            {
                float u = j * uv_step;
                float v = i * uv_step;
                uvs.push_back(glm::vec2(u, v));
            }
        }
    }
};
#endif