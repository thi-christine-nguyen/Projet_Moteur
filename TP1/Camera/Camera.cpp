#include <TP1/Camera/Camera.hpp>
#include <TP1/Camera/Camera_Helper.hpp>

// Include GLM
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <glm/gtc/type_ptr.hpp>
#include <iostream>

void Camera::init()
{
    m_fovDegree = 45.0f;
    m_position = glm::vec3(0.f, 40.f, 0.f);
    m_eulerAngle = glm::vec3(0.f, 0.f, 0.f);
    m_rotation = glm::quat{};
    m_translationSpeed = 15.0f;
    m_rotationSpeed = 1.0f;
    m_forwardDirection = glm::vec3(0.0f, 0.0f, -1.0f); // La caméra commence à regarder vers l'avant
    m_rightDirection = glm::vec3(1.0f, 0.0f, 0.0f); // La direction droite initiale
    m_upDirection = glm::vec3(0.0f, 1.0f, 0.0f); // La direction vers le haut initiale
	m_inputMode = InputMode::Free;
    m_lastMouseX = 0.0;
    m_lastMouseY = 0.0;

	// Transition
	m_transitionDuration = 1.0f;
	m_transitioning = false;
	m_transitionElapsedTime = 0.0f;

	// Shake
	float shakeDuration = 2.0f;
    float positionAmplitude = 0.05f;
    float rotationAmplitude = 1.0f;
    float positionFrequency = 5.0f;
    float rotationFrequency = 5.0f;
    cameraShake = std::make_unique<CameraShake>(m_position, shakeDuration, positionAmplitude, rotationAmplitude, positionFrequency, rotationFrequency);
	cameraShake->startShake();
}

void Camera::updateInterface(float _deltaTime)
{
	// ImGUI window creation
	if (ImGui::Begin("Interface"))
	{
		ImGui::Separator();
		ImGui::Text("Welcome to this TP about Cameras! Press escape to close the exe");
		ImGui::Text("Long live to the cameras");
		ImGui::Separator();
		ImGui::Checkbox("show Imgui Demo", &m_showImguiDemo);

		// Affichage/Modification de la position de la caméra
		ImGui::Text("Camera Position");
		ImGui::DragFloat3("##CameraPosition", glm::value_ptr(m_position));

		// Affichage/Modification du pitch et du yaw de la caméra
		ImGui::Text("Camera Orientation (Pitch, Yaw)");
		ImGui::SliderAngle("Pitch", &m_eulerAngle.x, -90.0f, 90.0f);
		ImGui::SliderAngle("Yaw", &m_eulerAngle.y, -180.0f, 180.0f);
        // std::cout << m_eulerAngle.x <<std::endl; 

		// Réglage de la focale (FoV) de la caméra
		ImGui::Text("Field Of View");
		ImGui::SliderFloat("Field of View", &m_fovDegree, 1.0f, 120.0f);

		// Réglage de la vitesse de translation et de rotation
		ImGui::Text("Translation and Rotation speed");
		ImGui::SliderFloat("Translation Speed", &m_translationSpeed, 0.1f, 100.0f);
		ImGui::SliderFloat("Rotation Speed", &m_rotationSpeed, 0.1f, 10.0f);

        // Réglage de la durée de la transition
        ImGui::Text("Transition Duration");
        ImGui::SliderFloat("Transition Duration", &m_transitionDuration, 0.1f, 10.0f);

        // Paramètres d'édition du shake
        cameraShake->updateInterface();
		// Bouton pour jouer le shake
        if (ImGui::Button("Play Shake")) {
            cameraShake->startShake(); // Appel de la fonction pour jouer le shake
        }


		// Afficher l'information du mode courant
        ImGui::Text("Input Mode: %s", inputModes[(int)m_inputMode]);

        // Liste déroulante pour les modes d'inputs
        int currentMode = static_cast<int>(m_inputMode);
        if (ImGui::Combo("Input Mode", &currentMode, inputModes.data(), inputModes.size())) {
            // Mettre à jour le mode d'input lorsque l'utilisateur sélectionne une option
            m_inputMode = static_cast<InputMode>(currentMode);
        }

		// Bouton de réinitialisation
		if (ImGui::Button("Reset Camera Settings")) {
			resetWithTransition(_deltaTime);
		}
	}
	ImGui::End();

	if (m_showImguiDemo)
	{
		ImGui::ShowDemoWindow();
	}

}

void Camera::updateFreeInput(float _deltaTime, GLFWwindow* _window)
{
	// Vitesse de translation
    float translationSpeed = m_translationSpeed * _deltaTime;
    // Vitesse de rotation
    float rotationSpeed = m_rotationSpeed * _deltaTime;

    // Gérer le changement de mode d'input lorsque la touche "tab" est pressée
    if (glfwGetKey(_window, GLFW_KEY_C) == GLFW_PRESS) {
        m_inputMode = InputMode::Drone;
    }
    if (glfwGetKey(_window, GLFW_KEY_X) == GLFW_PRESS) {
        m_inputMode = InputMode::Free;
    }
    if (glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        cameraShake->startShake();
    }


	if (m_inputMode == InputMode::Drone) {  // Gestion des entrées utilisateur pour la translation de la caméra
        // Gestion des entrées utilisateur pour la translation de la caméra
        if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
            // Avancer dans le plan horizontal de la caméra
            m_position -= glm::normalize(glm::vec3(m_forwardDirection.x, 0.0f, m_forwardDirection.z)) * m_translationSpeed * _deltaTime;
        }
        if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
            // Reculer dans le plan horizontal de la caméra
            m_position += glm::normalize(glm::vec3(m_forwardDirection.x, 0.0f, m_forwardDirection.z)) * m_translationSpeed * _deltaTime;
        }
		if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
			// Déplacer vers la gauche
			m_position += m_rightDirection * m_translationSpeed * _deltaTime;
		}
		if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
			// Déplacer vers la droite
			m_position -= m_rightDirection * m_translationSpeed * _deltaTime;
		}
        if (glfwGetKey(_window, GLFW_KEY_Q) == GLFW_PRESS) {
            // Déplacer vers le bas
            m_position += m_forwardDirection * m_translationSpeed * _deltaTime;
        }
        if (glfwGetKey(_window, GLFW_KEY_E) == GLFW_PRESS) {
            // Déplacer vers le haut
            m_position -= m_forwardDirection * m_translationSpeed * _deltaTime;
        }

		// Rotation
		if (glfwGetKey(_window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			m_eulerAngle.y += rotationSpeed * 40.0;
            
		}
		if (glfwGetKey(_window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			m_eulerAngle.y -= rotationSpeed * 40.0;
		}
		if (glfwGetKey(_window, GLFW_KEY_UP) == GLFW_PRESS) {
			m_eulerAngle.x -= rotationSpeed * 40.0;
		}
		if (glfwGetKey(_window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			m_eulerAngle.x += rotationSpeed * 40.0;
		}
	}

	if (m_inputMode == InputMode::Free) {
        // Rotation de la caméra avec la souris
        double mouseX, mouseY;
        glfwGetCursorPos(_window, &mouseX, &mouseY);

        if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            double deltaX = mouseX - m_lastMouseX;
            double deltaY = mouseY - m_lastMouseY;

            m_eulerAngle.x += static_cast<float>(deltaY) * m_rotationSpeed * 0.075;
            m_eulerAngle.y -= static_cast<float>(deltaX) * m_rotationSpeed * 0.075;

            // Limiter l'angle de pitch entre -90 et 90 degrés pour éviter les retournements
            
            m_eulerAngle.x = glm::clamp(m_eulerAngle.x, -89.0f, 89.0f);
            // m_eulerAngle.x = m_eulerAngle%180; 
            
        }

        m_lastMouseX = mouseX;
        m_lastMouseY = mouseY;

        // Translation de la caméra avec les touches ZQSD
        if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
            m_position -= m_forwardDirection * translationSpeed;
        }
        if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
            m_position += m_forwardDirection * translationSpeed;
        }
        if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
            m_position += m_rightDirection * translationSpeed;
        }
        if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
            m_position -= m_rightDirection * translationSpeed;
        }
    }

    // Limiter l'angle de pitch entre -90 et 90 degrés pour éviter les retournements
    // m_eulerAngle.x = glm::clamp(m_eulerAngle.x, -89.0f, 89.0f);
}

void Camera::updateCameraRotation()
{
    // Clamper les angles de pitch et de yaw
    float clampedPitch = glm::clamp(m_eulerAngle.x, -90.0f, 90.0f);
    
    float clampedYaw = Camera_Helper::ClipAngle180(m_eulerAngle.y);
    

    // Application des angles pour modifier pitch et yaw
    glm::quat pitchQuat = glm::angleAxis(glm::radians(clampedPitch), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::quat yawQuat = glm::angleAxis(glm::radians(clampedYaw), glm::vec3(0.0f, 1.0f, 0.0f));
    m_rotation = yawQuat * pitchQuat;

    // Recalcul des vecteurs de directions
    m_forwardDirection = glm::normalize(glm::rotate(m_rotation, glm::vec3(0.0f, 0.0f, -1.0f)));
    m_rightDirection = glm::normalize(glm::rotate(m_rotation, glm::vec3(1.0f, 0.0f, 0.0f)));
    m_upDirection = glm::normalize(glm::cross(m_rightDirection, m_forwardDirection));
}

glm::vec3 Camera::interpolate(const glm::vec3& start, const glm::vec3& end, float ratio)
{
    // Utilisation d'une interpolation cosinus pour des transitions plus douces
    ratio = (1.0f - cos(ratio * glm::pi<float>())) * 0.5f;

    // Interpolation linéaire entre les valeurs de départ et d'arrivée
    return start * (1.0f - ratio) + end * ratio;
}

void Camera::resetWithTransition(float _deltaTime) {
    // Sauvegarder l'état actuel de la caméra
    glm::vec3 currentPosition = m_position;
    glm::vec3 currentEulerAngles = m_eulerAngle;

    // Définir les nouvelles valeurs pour la réinitialisation
    glm::vec3 resetPosition = glm::vec3(0.f, 40.f, 0.f);
    glm::vec3 resetEulerAngles = glm::vec3(0.f, 0.f, 0.f);

    // Définir la durée de la transition
    float transitionTime = m_transitionDuration; // Utilisez la valeur définie dans ImGui

    // Effectuer la transition en interpolant progressivement entre les états actuel et réinitialisé
    if (m_transitionElapsedTime < transitionTime) {
		m_transitioning = true;
        float currentFrame = glfwGetTime();
        float ratio = m_transitionElapsedTime / transitionTime;

        // Interpoler les positions et les angles
        glm::vec3 interpolatedPosition = interpolate(currentPosition, resetPosition, ratio);
        glm::vec3 interpolatedEulerAngles = interpolate(currentEulerAngles, resetEulerAngles, ratio);

		// std::cout << m_transitionElapsedTime << "/" << transitionTime << std::endl;

        // Mettre à jour la position et les angles de la caméra
        m_position = interpolatedPosition;
        m_eulerAngle = interpolatedEulerAngles;


        // Mettre à jour le temps écoulé
        m_transitionElapsedTime += _deltaTime;
    } else {
		m_transitioning = false;
		m_transitionElapsedTime = 0.0f;
	}

    // m_position = resetPosition;
    // m_eulerAngle = resetEulerAngles;
	// update(_deltaTime, _window);
}

void Camera::update(float _deltaTime, GLFWwindow* _window)
{
	updateInterface(_deltaTime);
	updateFreeInput(_deltaTime, _window);

	cameraShake->update(_deltaTime);
	// std::cout << m_position.x << "; " << m_position.y << "; " << m_position.z << std::endl;
	
	updateCameraRotation();
	if (m_transitioning)
		resetWithTransition(_deltaTime);

	Camera_Helper::computeFinalView(m_projectionMatrix, m_viewMatrix, m_position, m_rotation, m_fovDegree);
}