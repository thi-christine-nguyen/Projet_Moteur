#ifndef PHYSIC_MANAGER_HPP__
#define PHYSIC_MANAGER_HPP__

#include <vector>
#include "GameObject.hpp"

class PhysicManager {
private:
    std::vector<GameObject*> objects;

public:
    void addObject(GameObject* object) {
        objects.push_back(object);
    }

    // void removeObject(GameObject* object) {
    //     // Retirer l'objet du vecteur
    //     objects.erase(std::remove(object.begin(), object.end(), object), objects.end());
    // }

    void handleCollisions() {
        // Mettre à jour la physique de chaque objet
        for (size_t i = 0; i < objects.size(); ++i) {
            for (size_t j = i + 1; j < objects.size(); ++j) {
                // Vérification de la collision entre les objets i et j
                if (objects[i]->getBoundingBox().intersect(objects[j]->getBoundingBox())) {
                    // Gestion de la collision entre les objets i et j
                    objects[i]->handleCollision(*objects[j]);
                    objects[j]->handleCollision(*objects[i]);
                }
            }
        }
    }

};

#endif //PHYSIC_MANAGER_HPP__