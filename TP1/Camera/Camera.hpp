#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>

enum class InputMode {
    Mode1,
    Mode2
};

class Camera
{
public: 

	void init();
	void update(float _deltaTime, GLFWwindow* _window);
	void updateInterface(float _deltaTime);
	void updateFreeInput(float _deltaTime, GLFWwindow* _window);
	void updateCameraRotation(); 
	void updateCameraOrientation(); 
	void computeFinalView();

	glm::quat getRotation() const {return m_rotation;}
	glm::mat4 getViewMatrix() const {return m_viewMatrix;}
	glm::mat4 getProjectionMatrix() const {return m_projectionMatrix;}

private:

	//Camera parameters 
	float		m_fovDegree{ 45.0f };
	glm::vec3	m_position{ glm::vec3(0.f, 40.f, 0.f) };
	glm::vec3	m_eulerAngle{ glm::vec3(0.f, 0.f, 0.f) };
	glm::quat	m_rotation{};
	float 		m_translationSpeed;
	float 		m_rotationSpeed; 
	glm::vec3 m_front;
    glm::vec3 m_up;
	glm::vec3 m_right;
	

	//Interface option
	bool m_showImguiDemo{ false };
	InputMode m_inputMode; 

	//View
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;
};