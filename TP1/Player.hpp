#ifndef PLAYER_HPP__
#define PLAYER_HPP__

#include "Sphere.hpp"

class Player : public Sphere{
public:

    Player(std::string name, unsigned int res, unsigned int rad, int textureID = 0, const char *texturePath = "")
         : Sphere(name, res, rad, textureID, texturePath) {
    }

    void handleInputs(GLFWwindow *window, float deltaTime){
        const float frictionCoefficient = 0.4f;
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && grounded) {
            // this->setVelocity(glm::vec3(0.0f, 3.0f, 0.0f));
            this->velocity.y = 3.0f;
        }

        // Mouvement vers la droite
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            this->acceleration.x += 1.0f;
            this->velocity.x += this->acceleration.x * deltaTime;
        }
        // Mouvement vers la gauche
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            this->acceleration.x -= 1.0f;
            this->velocity.x += this->acceleration.x * deltaTime;
        }
        // Mouvement vers le haut
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            this->acceleration.z += 1.0f;
            this->velocity.z += this->acceleration.z * deltaTime;
        }
        // Mouvement vers le bas
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            this->acceleration.z -= 1.0f;
            this->velocity.z += this->acceleration.z * deltaTime;
        }

        // Appliquer le coefficient de friction pour réduire progressivement la vélocité dans les deux directions (X et Y)
        if (this->velocity.x > 0) {
            this->velocity.x -= frictionCoefficient;
        } else if (this->velocity.x < 0) {
            this->velocity.x += frictionCoefficient;
        }

        if (this->velocity.z > 0) {
            this->velocity.z -= frictionCoefficient;
        } else if (this->velocity.z < 0) {
            this->velocity.z += frictionCoefficient;
        }

        // Mettre à jour la vitesse en fonction de l'accélération
        
        
    }
};
#endif