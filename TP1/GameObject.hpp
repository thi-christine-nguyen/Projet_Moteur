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
    PLAYER,
    MESH
};

// Structure pour représenter un triangle
struct Triangle {
    glm::vec3 v0;
    glm::vec3 v1;
    glm::vec3 v2;
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
    float weight = 1.f;
    bool grounded = false;
    float restitutionCoef = 0.6f;

    // TEXTURE
    int textureID; // 0 = flatColor sinon Texture
    const char *texturePath;

    // INTERFACE
    bool scaleLocked_ ;
    bool gravityEnabled_;

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

    // Accesseur pour les triangles
    const std::vector<std::vector<unsigned short>>& getTriangles() const {
        return triangles;
    }

    // Accesseur pour les sommets (vertices)
    const std::vector<glm::vec3>& getVertices() const {
        return vertices;
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
    void GenerateBuffers(GLuint programID)
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

    void DeleteBuffers(GLuint programID)
    {
        glDeleteBuffers(1, &vboVertices);
        glDeleteBuffers(1, &vboIndices);
        glDeleteBuffers(1, &vboUV);
        glDeleteVertexArrays(1, &vao);
        glDeleteProgram(programID);
        for (GameObject *child : children)
        {
            child->DeleteBuffers(programID);
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

    void initTexture(GLuint programID) {
        if (textureID != 0) { // S'il y a une texture sur le GameObject
            std::cout << textureID << ": " << texturePath << std::endl;
            glActiveTexture(GL_TEXTURE0);
            loadTexture2DFromFilePath(texturePath);
            glUniform1i(glGetUniformLocation(programID, "gameObjectTexture"), 0);
        }
        for (GameObject *child : children) {
            child->initTexture(programID);
        }
    }

    /* ------------------------- PHYSICS -------------------------*/

    void updatePhysicallyBasedPosition(float deltaTime) {
        // Application de la force gravitationnelle
        if (gravityEnabled_  && !grounded)
            velocity += acceleration * deltaTime;

        // Application de sa vitesse à notre objet
        if (gravityEnabled_){
            translate(velocity * deltaTime);
        }
    }

    // Fonction pour vérifier si un point est à l'intérieur d'un triangle
    bool pointInsideTriangle(const glm::vec3& point, const Triangle& triangle) {
        glm::vec3 edge0 = triangle.v1 - triangle.v0;
        glm::vec3 edge1 = triangle.v2 - triangle.v0;
        glm::vec3 pointVec = point - triangle.v0;

        float dot00 = glm::dot(edge0, edge0);
        float dot01 = glm::dot(edge0, edge1);
        float dot02 = glm::dot(edge0, pointVec);
        float dot11 = glm::dot(edge1, edge1);
        float dot12 = glm::dot(edge1, pointVec);

        float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
        float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
        float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

        return (u >= 0) && (v >= 0) && (u + v < 1);
    }

    // Fonction pour détecter et réagir aux collisions avec les triangles
    void handleTriangleCollision(const GameObject& other) {
        for (const auto& triangleIndices : other.getTriangles()) {
            Triangle tri;
            tri.v0 = other.getVertices()[triangleIndices[0]];
            tri.v1 = other.getVertices()[triangleIndices[1]];
            tri.v2 = other.getVertices()[triangleIndices[2]];

            if (pointInsideTriangle(transform.getPosition(), tri)) {
                // Collision detected with triangle
                // React accordingly (adjust position or velocity)
                std::cout << "Mesh collision: " << name << " and " << other.getName() << std::endl;
                std::cout << "Collision detected with triangle" << std::endl;
                std::cout << "Collision point: " << transform.getPosition().x << ", " << transform.getPosition().y << ", " << transform.getPosition().z << std::endl;
                exit(1);
            }
        }
    }

    bool triangleCollision(const Triangle& tri1, const Triangle& tri2) {
        // Fonction utilitaire pour calculer le produit vectoriel de deux vecteurs
        auto crossProduct = [](const glm::vec3& v1, const glm::vec3& v2) {
            return glm::vec3(
                v1.y * v2.z - v1.z * v2.y,
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x
            );
        };

        // Fonction utilitaire pour normaliser un vecteur
        auto normalize = [](const glm::vec3& v) {
            return glm::normalize(v);
        };

        // Axes de séparation potentiels (normales aux arêtes des triangles)
        glm::vec3 axes[] = {
            normalize(crossProduct(tri1.v1 - tri1.v0, tri1.v2 - tri1.v0)),
            normalize(crossProduct(tri2.v1 - tri2.v0, tri2.v2 - tri2.v0)),
            normalize(tri1.v1 - tri1.v0),
            normalize(tri1.v2 - tri1.v1),
            normalize(tri1.v0 - tri1.v2),
            normalize(tri2.v1 - tri2.v0),
            normalize(tri2.v2 - tri2.v1),
            normalize(tri2.v0 - tri2.v2)
        };

        // Fonction utilitaire pour projeter un triangle sur un axe et renvoyer son intervalle
        auto projectTriangle = [](const Triangle& tri, const glm::vec3& axis) {
            float min = glm::dot(axis, tri.v0);
            float max = min;
            for (const glm::vec3& vertex : {tri.v1, tri.v2}) {
                float projection = glm::dot(axis, vertex);
                if (projection < min) min = projection;
                else if (projection > max) max = projection;
            }
            return std::make_pair(min, max);
        };

        // Test de séparation d'axes
        for (const glm::vec3& axis : axes) {
            auto [min1, max1] = projectTriangle(tri1, axis);
            auto [min2, max2] = projectTriangle(tri2, axis);
            if (max1 < min2 || max2 < min1) {
                // Il y a séparation sur cet axe, pas de collision
                return false;
            }
        }

        // Aucune séparation sur tous les axes, donc les triangles se chevauchent
        return true;
    }

    // Fonction handleMeshCollision
    void handleMeshCollision(const GameObject& other) {
        const auto& triangles1 = getTriangles();
        const auto& vertices1 = getVertices();
        const auto& triangles2 = other.getTriangles();
        const auto& vertices2 = other.getVertices();

        for (const auto& triangleIndices1 : triangles1) {
            for (const auto& triangleIndices2 : triangles2) {
                Triangle tri1;
                tri1.v0 = vertices1[triangleIndices1[0]];
                tri1.v1 = vertices1[triangleIndices1[1]];
                tri1.v2 = vertices1[triangleIndices1[2]];

                Triangle tri2;
                tri2.v0 = vertices2[triangleIndices2[0]];
                tri2.v1 = vertices2[triangleIndices2[1]];
                tri2.v2 = vertices2[triangleIndices2[2]];

                // Check collision between tri1 and tri2
                if (triangleCollision(tri1, tri2)) {
                    std::cout << "Mesh collision: " << name << " and " << other.getName() << std::endl;
                    std::cout << "Collision detected with triangle" << std::endl;
                    std::cout << "Collision point: " << transform.getPosition().x << ", " << transform.getPosition().y << ", " << transform.getPosition().z << std::endl;
                    std::cout << "BeginOverlap" << std::endl;
                    grounded = true;
                    std::cout << "vitesse avant: " << getVelocity().x << "; " << getVelocity().y << "; " << getVelocity().z << std::endl;
                    setVelocity(length(getVelocity()) > 1.0f ? getVelocity() * restitutionCoef * glm::vec3(1.0f, -1.0f, 1.0f): glm::vec3(0.0f));
                    std::cout << "vitesse apres: " << getVelocity().x << "; " << getVelocity().y << "; " << getVelocity().z << std::endl;
                    exit(1);
                    return;
                } else {
                    // std::cout << "Pas de collision: " << name << std::endl;
                    
                    if (grounded) { // endOverlap
                        std::cout << "EndOverlap" << std::endl;
                        grounded = false;
                    }
                }
            }
        }
    }

    // Méthode pour détecter et résoudre les collisions avec un autre GameObject
    void handleCollision(const GameObject& other) {
        if (boundingBox.intersect(other.getBoundingBox())) {
            if (other.getType() == GameObjectType::PLANE) { // Collision avec le landscape
            // Collision entre le GameObject et le terrain détectée
            // Vérifiez la collision avec les AABB
                // std::cout << "Collision entre le GameObject (" << getName() << ") et le terrain (" << other.getName() << ") détectée" << std::endl;
                if (!grounded) { // Si elle n'était pas déjà au sol alors beginOverlap
                    std::cout << "BeginOverlap" << std::endl;
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
                // Régler la position du GameObject sur le terrain
                // transform.setPosition(glm::vec3(transform.getPosition().x, other.getTransform().getPosition().y, transform.getPosition().z));

                // Réinitialiser la vitesse du GameObject à zéro
            } else {
                if (grounded) { // endOverlap
                    std::cout << "EndOverlap" << std::endl;
                    grounded = false;
                }
            }
        }
        if (other.getType() == GameObjectType::MESH) {
            handleMeshCollision(other);
        }
    }

    bool isGrounded() {return grounded;}

    /* ------------------------- UPDATE -------------------------*/
    // Elements à mettre à jour à chaque frame ou tick de mise à jour

    void update(float deltaTime) {
        updatePhysicallyBasedPosition(deltaTime);
    }

    std::unique_ptr<GameObject> ptr; // Pointeur unique vers l'objet

    /* ------------------------- INTERFACE -------------------------*/

    void resetParameters() {
        // Réinitialiser la transformation à sa valeur par défaut
        transform = Transform();

        // Réinitialiser d'autres paramètres selon vos besoins
        scaleLocked_ = false;
        gravityEnabled_ = false;
    }

    void updateInterfaceTransform(float _deltaTime) {
        ImGui::Text("Position");
        glm::vec3 position = transform.getPosition();
        ImGui::DragFloat3(("##" + name + "Position").c_str(), glm::value_ptr(position));

        glm::vec3 rotation = transform.getRotation();
        ImGui::Text("Rotation");
        ImGui::DragFloat3(("##" + name + "Rotation").c_str(), glm::value_ptr(rotation));

        glm::vec3 scale = transform.getScale();

        ImGui::Text("Lock Scale");
        ImGui::SameLine();
        ImGui::Checkbox(("##" + name + "LockScale").c_str(), &scaleLocked_);

        if (scaleLocked_) {
            // Si l'échelle est verrouillée, utilisez une seule valeur pour les trois axes
            ImGui::Text("Scale");
            ImGui::DragFloat(("##" + name + "Scale").c_str(), &scale.x);
            scale.y = scale.x;
            scale.z = scale.x;
        } else {
            ImGui::Text("Scale x, y, z");
            // Sinon, laissez l'utilisateur modifier chaque valeur de l'échelle individuellement
            ImGui::DragFloat3(("##" + name + "Scale").c_str(), glm::value_ptr(scale));
        }

        ImGui::Text("Gravity Enabled");
        ImGui::SameLine();
        ImGui::Checkbox(("##" + name + " GravityEnabled").c_str(), &gravityEnabled_);

        transform.setPosition(position);
        transform.setRotation(rotation);
        transform.setScale(scale);

        if (ImGui::Button(("Reset " + name + " Parameters").c_str())) {
            resetParameters(); // Appeler la fonction pour réinitialiser les paramètres lorsque le bouton est cliqué
        }
    }


};

#endif