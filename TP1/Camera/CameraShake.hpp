#ifndef CAMERASHAKE_HPP__
#define CAMERASHAKE_HPP__

#include <glm/glm.hpp>
#include <imgui/imgui.h>
#include <iostream>

class CameraShake {
public:
    CameraShake(glm::vec3& cameraPosition, float _duration, 
                float _positionAmplitude, float _rotationAmplitude, 
                float _positionFrequency, float _rotationFrequency) 
        : m_cameraPosition(cameraPosition), duration(_duration), 
          positionAmplitude(_positionAmplitude), positionFrequency(_positionFrequency), 
          rotationAmplitude(_rotationAmplitude), rotationFrequency(_rotationFrequency), 
          elapsedTime(0.0f), isShaking(false) {}

    void startShake() {
        isShaking = true;
        elapsedTime = 0.0f;
    }

    void update(float _deltaTime) {
       if (!isShaking) return;
        elapsedTime += _deltaTime;
        if (elapsedTime >= duration) {
            isShaking = false;
            return;
        }

        // Calcul du déplacement de la caméra en fonction du temps écoulé
        float displacement = positionAmplitude * glm::cos(positionFrequency * elapsedTime);

        // Appliquer le déplacement à la position de la caméra
        glm::vec3 shakeOffset = glm::vec3(displacement, displacement, displacement); // Ajustez selon vos besoins
        // Appliquer le décalage de shake à la position de la caméra
        // Vous devrez adapter cette partie à votre implémentation spécifique de la caméra
        m_cameraPosition.y += shakeOffset.y;
    }


    void updateInterface() {
        ImGui::Text("Shake Settings");
        ImGui::SliderFloat("Duration", &duration, 1.0f, 15.0f);
        ImGui::SliderFloat("Position Amplitude", &positionAmplitude, 0.1f, 1.0f);
        ImGui::SliderFloat("Rotation Amplitude", &rotationAmplitude, 0.1f, 2.0f);
        ImGui::SliderFloat("Position Frequency", &positionFrequency, 0.1f, 10.0f);
        ImGui::SliderFloat("Rotation Frequency", &rotationFrequency, 0.1f, 10.0f);
    }

private:
    float duration;
    float positionAmplitude;
    float rotationAmplitude;
    float positionFrequency;
    float rotationFrequency;
    float elapsedTime;
    bool isShaking;
    glm::vec3 &m_cameraPosition; // Position de la caméra
};

#endif // CAMERASHAKE_HPP__
