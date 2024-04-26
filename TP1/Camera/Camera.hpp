#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include <array>
#include <memory>
#include "CameraShake.hpp"

enum class InputMode
{
	Drone,
	Fixed,
	Free
};

class Camera
{
public: 

	void init();
	void update(float _deltaTime, GLFWwindow* _window);
	void updateInterface(float _deltaTime);
	void updateFreeInput(float _deltaTime, GLFWwindow* _window);
	void updateCameraRotation();
	void resetWithTransition(float _deltaTime);

	glm::quat getRotation() const {return m_rotation;}
	glm::mat4 getViewMatrix() const {return m_viewMatrix;}
	glm::mat4 getProjectionMatrix() const {return m_projectionMatrix;}

private:

	//Camera parameters 
	float		m_fovDegree{ 45.0f };
	float		m_translationSpeed;
	float 		m_rotationSpeed;
	glm::vec3	m_position{ glm::vec3(0.f, 40.f, 0.f) };
	glm::vec3	m_eulerAngle{ glm::vec3(0.f, 0.f, 0.f) };
	glm::quat	m_rotation{};

    // Directions de la caméra
    glm::vec3 m_forwardDirection;
    glm::vec3 m_rightDirection;
    glm::vec3 m_upDirection;

	//Interface option
	bool m_showImguiDemo{ false };

	// Input Mode
    std::array<const char*, 3> inputModes = { "Drone", "Fixed", "Free" };
	InputMode m_inputMode;

	// mouseInputs
    double m_lastMouseX;
    double m_lastMouseY;

	//View
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

	// smoothTransitions
    bool m_transitioning; // Indique si une transition est en cours
    double m_transitionElapsedTime; // Temps au début de la transition
    float m_transitionDuration; // Durée de la transition

    // Fonction d'interpolation pour la transition
    glm::vec3 interpolate(const glm::vec3& start, const glm::vec3& end, float ratio);

	// Définition des paramètres du shake
	std::unique_ptr<CameraShake> cameraShake;
};