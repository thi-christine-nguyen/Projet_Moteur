#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

// UniquePtr
#include <memory>

#include <string>
#include <cstring>
#include <cstdio>

// Include standard headers
#include "lib.hpp"
#include "Transform.hpp"
#include "BoundingBox.hpp"

enum GameObjectType { 
    DEFAULT,
    SPHERE,
    CUBE,
    PLANE,
    LANDSCAPE,
    PLAYER
};

class GameObject {
protected:
    // GENERAL
    Transform transform;  // Transform de l'objet
    GameObjectType type; // Type du GameObject
    std::string name; // Nom et identifiant de l'objet

    // HIERARCHY
    std::vector<GameObject*> children;  // Liste des enfants de cet objet
    GameObject *parent; // Référence vers le parent de l'objet

    // BUFFERS
    GLuint vao;
    GLuint vboVertices;
    GLuint vboIndices;
    GLuint vboUV;

    // UNIFORM LOCATION
    GLuint typeULoc;
    GLuint transformULoc;
    GLuint colorULoc;
    GLuint textureULoc;
    GLuint textureIdULoc;

    // MESH DATA
    std::vector<unsigned short> indices;
    std::vector<std::vector<unsigned short>> triangles;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    glm::vec4 color;

    // PHYSICS
    BoundingBox boundingBox;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float weight = 0.f;
    bool grounded = false;
    float restitutionCoef = 0.6f;

    // TEXTURE
    int textureID; // 0 = flatColor sinon Texture
    const char *texturePath;

public:
    /* ------------------------- CONSTRUCTOR -------------------------*/

    // Constructeur prenant une transformation optionnelle
    GameObject(std::string name = "", int textId = 0, const Transform& initialTransform = Transform(), GameObject* parent = nullptr, GameObjectType type = GameObjectType::DEFAULT)
        : name(name), textureID(textId), transform(initialTransform), parent(parent), type(type) {
        ptr.reset(this);
    }

    // Méthode pour ajouter un enfant à cet objet
    void addChild(GameObject* child) {
        children.push_back(child);
        child->parent = this;
    }

    // Initialise la bounding box selon les vertices du GameObject
    void initBoundingBox() {
        boundingBox.init(vertices);
        glm::vec3 min = boundingBox.getMin();
        glm::vec3 max = boundingBox.getMax();
        // std::cout << "Initialisation of bounding box done : min(" << min.x << "; " << min.y << "; " << min.z << ") / max(" << max.x << "; " << max.y << "; " << max.z << ")" << std::endl;
    }

    /* ------------------------- GETTERS/SETTERS -------------------------*/

    // Méthode pour obtenir la transformation de cet objet
    const Transform& getTransform() const {
        return transform;
    }

    // Méthode pour définir la transformation de cet objet
    void setTransform(const Transform& newTransform) {
        transform = newTransform;
    }

    // Méthode pour modifier la position de cet objet
    void setPosition(glm::vec3 pos) {
        transform.setPosition(pos);
    }

    // Méthodes pour accéder et modifier le parent de cet objet
    GameObject* getParent() const {
        return parent;
    }

    void setParent(GameObject* newParent) {
        parent = newParent;
    }

    // Méthodes pour accéder et modifier le type de cet objet
    GameObjectType getType() const {
        return type;
    }

    void setType(GameObjectType newType) {
        type = newType;
    }

    //Méthodes pour accéder et modifier le nom de cet objet

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    // Méthodes pour accéder et modifier la couleur de cet objet
    glm::vec4 getColor() const {
        return color;
    }

    void setColor(glm::vec4 newColor) {
        color = newColor;
    }

    // Méthodes pour accéder et modifier la vitesse de cet objet
    glm::vec3 getVelocity() const {
        return velocity;
    }

    void setVelocity(glm::vec3 newVelocity) {
        velocity = newVelocity;
    }

    // Méthodes pour accéder et modifier l'accélération de cet objet
    glm::vec3 getAcceleration() const {
        return acceleration;
    }

    void setAcceleration(glm::vec3 newAcceleration) {
        acceleration = newAcceleration;
    }

    // Méthodes pour accéder et modifier le poids de cet objet
    float getWeight() const {
        return weight;
    }

    void setWeight(float newWeight) {
        weight = newWeight;
        acceleration = glm::vec3(0.f, weight * -9.81, 0.f);
    }

    // Getter pour la boîte englobante
    const BoundingBox& getBoundingBox() const {
        return boundingBox;
    }

    // Setter pour la boîte englobante
    void setBoundingBox(const BoundingBox& bbox) {
        boundingBox = bbox;
    }

    /* ------------------------- TRANSFORMATIONS -------------------------*/

    void translate(const glm::vec3 &translation) { transform.translate(translation); boundingBox.updateAfterTransformation(vertices, transform.getMatrix());}
    void scale(const glm::vec3 &scale) { transform.scale(scale); boundingBox.updateAfterTransformation(vertices, transform.getMatrix());}
    void rotate(float angle, const glm::vec3 &axis) { transform.rotate(angle, axis); boundingBox.updateAfterTransformation(vertices, transform.getMatrix());}

    glm::mat4 getWorldBasedTransform() const {
        return parent == nullptr ? transform.getMatrix() : parent->getWorldBasedTransform() * transform.getMatrix();
    }

    /* ------------------------- BUFFERS -------------------------*/
    void GenerateBuffers()
    {
        glGenVertexArrays(1, &vao);    // Le VAO qui englobe tout
        glGenBuffers(1, &vboVertices); // VBO vertex
        glGenBuffers(1, &vboUV);        // VBO uv
        glGenBuffers(1, &vboIndices);  // VBO d'élements indices pour draw triangles

        transformULoc = glGetUniformLocation(programID, "transform");
        typeULoc = glGetUniformLocation(programID, "type");
        colorULoc = glGetUniformLocation(programID, "color");
        textureULoc = glGetUniformLocation(programID, "gameObjectTexture");
        textureIdULoc = glGetUniformLocation(programID, "textureID");

        // Binds + Chargement des buffers avec les donnéees de l'objets courant
        // Vertices
        glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
        // UV
        glBindBuffer(GL_ARRAY_BUFFER, vboUV);
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * uvs.size(), &uvs[0], GL_STATIC_DRAW);
        // Indices
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndices);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short) * indices.size(), &indices[0], GL_STATIC_DRAW);
    }

    void DeleteBuffers()
    {
        glDeleteBuffers(1, &vboVertices);
        glDeleteBuffers(1, &vboIndices);
        glDeleteBuffers(1, &vboUV);
        glDeleteVertexArrays(1, &vao);
        glDeleteProgram(programID);
        for (GameObject *child : children)
        {
            child->DeleteBuffers();
        }
    };

    virtual void draw() const
    {
        glBindVertexArray(vao); // Bind le giga vecteur array
        // Envoi du type du GameObject
        glUniform1i(typeULoc, type);
        // Envoi de la matrice de transformation
        glUniformMatrix4fv(transformULoc, 1, false, &getWorldBasedTransform()[0][0]);
        // Envoi de la couleur du GameObject
        glUniform4fv(colorULoc, 1, &color[0]);
        // Activer la texture appropriée
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureID);
        // Envoi de la texture du GameObject
        glUniform1i(textureULoc, 0);

        // Bind et Envoi de la liste pré chargée des vertices
        glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
        glEnableVertexAttribArray(0); // Dans le layout 0

        // Bind et Envoi de la liste pré chargée des UVs
        glBindBuffer(GL_ARRAY_BUFFER, vboUV);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void *)0);
        glEnableVertexAttribArray(1); // Dans le layout 1

        // Bind et Envoi du textID pour appliquer la bonne texture sur le GameObject
        glUniform1i(textureIdULoc, textureID);

        // Activer la texture appropriée
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureID);
        // Passer l'ID de texture à votre shader
        glUniform1i(textureULoc, 0); // Utilisez l'unité de texture 0

        // Bind et Draw les triangles et recurse le draw sur les enfants
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndices);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);
        // std::cout << type << std::endl;
        for (const GameObject *child : children) {
            child->draw();
        }
        // boundingBox.draw(glm::vec3(255.0f));
        glBindVertexArray(0); // Delink le VAO si plus tard on utilise plusieurs VAO
        //  Desactiver les layouts après avoir dessiner
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    }

    /* ------------------------- TEXTURES -------------------------*/

    void initTexture() {
        if (textureID != 0) { // S'il y a une texture sur le GameObject
            std::cout << textureID << ": " << texturePath << std::endl;
            glActiveTexture(GL_TEXTURE0);
            loadTexture2DFromFilePath(texturePath);
            glUniform1i(glGetUniformLocation(programID, "gameObjectTexture"), 0);
        }
        for (GameObject *child : children) {
            child->initTexture();
        }
    }

    /* ------------------------- PHYSICS -------------------------*/

    void updatePhysicallyBasedPosition(float deltaTime) {
        // Application de la force gravitationnelle
        if (!grounded)
            velocity += acceleration * deltaTime;

        // Application de sa vitesse à notre objet
        translate(velocity * deltaTime);
    }
    // Fonction pour calculer les impulsions à appliquer à chaque objet
    void calculer_impulsions(const GameObject& obj2, glm::vec3& impulsion1, glm::vec3& impulsion2, const glm::vec3& normale_contact) {
        // Calcul des impulsions en utilisant les lois de la physique
        // Ici, nous utilisons une approche simplifiée pour l'exemple
        float restitution_coefficient = 0.5f; // Coefficient de restitution
        float impulse_factor = (1.0f + restitution_coefficient) * glm::dot(obj2.getVelocity() - getVelocity(), normale_contact) / (1 / getWeight() + 1 / obj2.getWeight());
        impulsion1 = impulse_factor * normale_contact / getWeight();
        impulsion2 = -impulse_factor * normale_contact / obj2.getWeight();
    }

    // Méthode pour détecter et résoudre les collisions avec un autre GameObject
    void handleCollisionWithLandscape(const GameObject& other) {
        if (other.getType() == GameObjectType::PLANE) {
            // Collision entre le GameObject et le terrain détectée
            // Vérifiez la collision avec les AABB
            if (boundingBox.intersect(other.getBoundingBox())) {
                // std::cout << "Collision entre le GameObject (" << getName() << ") et le terrain (" << other.getName() << ") détectée" << std::endl;
                if (!grounded) { // Si elle n'était pas déjà au sol alors beginOverlap
                    grounded = true;
                    std::cout << "vitesse avant: " << getVelocity().x << "; " << getVelocity().y << "; " << getVelocity().z << std::endl;
                    setVelocity(length(getVelocity()) > 1.0f ? getVelocity() * restitutionCoef * glm::vec3(1.0f, -1.0f, 1.0f): glm::vec3(0.0f));
                    std::cout << "vitesse apres: " << getVelocity().x << "; " << getVelocity().y << "; " << getVelocity().z << std::endl;
                }
                // Calcul des impulsions
                // glm::vec3 impulsion1, impulsion2, normale_contact = glm::normalize(other.getTransform().getPosition() - transform.getPosition());
                // calculer_impulsions(other, impulsion1, impulsion2, normale_contact);
                // std::cout << "normale contact: " << normale_contact.x << "; " << normale_contact.y << "; " << normale_contact.z << std::endl;
                // std::cout << "impulsion: " << impulsion1.x << "; " << impulsion1.y << "; " << impulsion1.z << std::endl;
                // Réglez la position du GameObject sur le terrain
                // transform.setPosition(glm::vec3(transform.getPosition().x, other.getTransform().getPosition().y, transform.getPosition().z));

                // Réinitialisez la vitesse du GameObject à zéro
            } else {
                if (grounded) // endOverlap
                    grounded = false;
            }
        }
    }

    bool isGrounded() {return grounded;}

    /* ------------------------- UPDATE -------------------------*/

    void update(float deltaTime) {
        updatePhysicallyBasedPosition(deltaTime);
    }

    std::unique_ptr<GameObject> ptr; // Pointeur unique vers l'objet
};

#endif