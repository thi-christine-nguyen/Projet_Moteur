#ifndef SCENE_MANAGER_HPP__
#define SCENE_MANAGER_HPP__

#include <vector>
#include <memory> // Pour std::unique_ptr
#include "lib.hpp"
#include "GameObject.hpp"

class SceneManager {
private:
    GLuint programID; 
    std::vector<std::unique_ptr<GameObject>> objects; // Vecteur de pointeurs uniques vers les objets de la scène ce qui garantit que chaque GameObject est géré par un unique SceneManager

public:
    SceneManager(GLuint programID) : programID(programID) {}

    // Méthode pour ajouter un objet à la scène
    void addObject(std::unique_ptr<GameObject> object) {
        objects.push_back(std::move(object)); // std::move permet de transférer la responsabilité de gestion de l'objet au SceneManager
    }

    // Méthode pour mettre à jour tous les objets de la scène
    void update(float deltaTime) {
        for (const auto& object : objects) {
            // Mettre à jour l'objet
            object->update(deltaTime);
        }
    }

    // void handleCollisions() {
    //     // Mettre à jour la physique de chaque objet
    //     for (size_t i = 0; i < objects.size(); ++i) {
    //         for (size_t j = i + 1; j < objects.size(); ++j) {
    //             // Vérification de la collision entre les objets i et j
    //             if (i != j) {
    //                 if (objects[i]->getBoundingBox().intersect(objects[j]->getBoundingBox())) {
    //                     // Gestion de la collision entre les objets i et j
    //                     objects[i]->handleCollision(*objects[j]);
    //                     objects[j]->handleCollision(*objects[i]);
    //                 }
    //             }
    //         }
    //     }
    // }

    // Méthode pour afficher tous les objets de la scène
    void draw() {
        for (const auto& object : objects) {
            // Afficher l'objet
            object->draw();
        }
    }

    void initGameObjectsTexture() {
        for (const auto& object : objects) {
            // Init la texture de l'objet
            object->initTexture(programID);
        }
    }

    GameObject *getObjectByName(const std::string& name) {
        for (const auto& object : objects) {
            if (object->getName() == name)
                return object.get();
        }
        return nullptr;
    }

    std::vector<std::unique_ptr<GameObject>>& getObjects() {
        return objects;
    }

    void removeObjectByName(const std::string& name) {
        auto it = std::remove_if(objects.begin(), objects.end(), [&name](const std::unique_ptr<GameObject>& obj) {
            return obj->getName() == name;
        });
        objects.erase(it, objects.end());
    }
};

#endif