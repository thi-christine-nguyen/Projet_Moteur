#ifndef PLAYER_HPP__
#define PLAYER_HPP__

#include "Sphere.hpp"

class Player : public Sphere{
public:

    Player(std::string name, unsigned int res, unsigned int rad, int textureID = 0, const char *texturePath = "")
         : Sphere(name, res, rad, textureID, texturePath) {
    }

    void handleInputs(GLFWwindow *window, float deltaTime){
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && grounded) {
            this->setVelocity(glm::vec3(0.0f, 3.0f, 0.0f));
        }
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && grounded){
            this->acceleration.x += 1.0f;
            this->velocity.x += acceleration.x * deltaTime;
        }
    }
};
#endif