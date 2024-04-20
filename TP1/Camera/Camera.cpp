#include <TP1/Camera/Camera.hpp>
#include <TP1/Camera/Camera_Helper.hpp>

// Include GLM
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <glm/gtc/type_ptr.hpp>
#include <iostream> 
#include <vector> 



void Camera::init()
{
	m_fovDegree = 45.0f;
	m_position = glm::vec3(0.f, 0.f, 0.f);
	m_eulerAngle = glm::vec3(0.f, 0.f, 0.f);
	m_rotation = glm::quat{};
	m_showImguiDemo = false;
	m_translationSpeed = 10; 
	m_rotationSpeed = 0.1; 
	m_front = glm::vec3(0.0f, 0.0f, -1.0f); // La caméra regarde vers l'avant
    m_up = glm::vec3(0.0f, 1.0f, 0.0f);  
	m_right = glm::vec3(1.0f, 0.0f, 0.0f);
	m_inputMode = InputMode::Mode1; 
	
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
		ImGui::Text("Camera Position:");
        ImGui::DragFloat3("##Position", glm::value_ptr(m_position), 0.1f);

		// Affichage/Modification du pitch et du yaw de la caméra (en utilisant des angles d'Euler)
		ImGui::Text("Camera Orientation (Pitch, Yaw):");
		float clippedPitch = Camera_Helper::clipAngle(m_eulerAngle.y, 90.0f);
        ImGui::SliderAngle("Pitch", &m_eulerAngle.x, -90.0f, 90.0f);
		
        ImGui::SliderAngle("Yaw", &m_eulerAngle.y, -180.0f, 180.0f);
		

		// Réglage de la focale (FoV) de la caméra
        ImGui::Text("Camera Field of View (FoV):");
        ImGui::SliderFloat("FoV", &m_fovDegree, 1.0f, 180.0f);

		// Réglage de la vitesse de translation de la caméra
        ImGui::Text("Camera Translation Speed:");
        ImGui::SliderFloat("Translation Speed", &m_translationSpeed, 5.0f, 20.0f);

        // Réglage de la vitesse de rotation de la caméra
        ImGui::Text("Camera Rotation Speed:");
        ImGui::SliderFloat("Rotation Speed", &m_rotationSpeed, 0.1f, 1.0f);

		// Reset Bouton
		if(ImGui::Button("Reset Parameters")){
			init(); 
			
		}

        ImGui::Text("Current Mode: %s",(m_inputMode == InputMode::Mode1) ? "Translation/Rotation Mode" : "Free Mode");

		if (ImGui::Button("Toggle Mode (M)")) {
			m_inputMode = (m_inputMode == InputMode::Mode1) ? InputMode::Mode2 : InputMode::Mode1;
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

	static bool tabPressed = false;

    if (glfwGetKey(_window, GLFW_KEY_L) == GLFW_PRESS && !tabPressed) {
        m_inputMode = (m_inputMode == InputMode::Mode1) ? InputMode::Mode2 : InputMode::Mode1;

        tabPressed = true;
    } else if (glfwGetKey(_window, GLFW_KEY_L) == GLFW_RELEASE) {
        tabPressed = false;
    }

	// Vitesse de translation
    float translationSpeed = m_translationSpeed * _deltaTime;
    // Vitesse de rotation
    float rotationSpeed = m_rotationSpeed * _deltaTime;

	if (m_inputMode == InputMode::Mode1) {
		
		double mouseX, mouseY;
        glfwGetCursorPos(_window, &mouseX, &mouseY);
        static double lastMouseX = mouseX;
        static double lastMouseY = mouseY;

        double deltaX = mouseX - lastMouseX;
        double deltaY = mouseY - lastMouseY;

        m_eulerAngle.x += static_cast<float>(deltaY) * rotationSpeed;
		m_eulerAngle.x = Camera_Helper::clipAngle(glm::degrees(m_eulerAngle.x), 90);
		
        m_eulerAngle.y -= static_cast<float>(deltaX) * rotationSpeed;
		m_eulerAngle.y = Camera_Helper::clipAngle(glm::degrees(m_eulerAngle.y), 180);

        lastMouseX = mouseX;
        lastMouseY = mouseY;

        // Keyboard input for camera translation
        if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
            m_position += m_front * translationSpeed;
        }
        if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
            m_position -= m_front * translationSpeed;
        }
       	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
			m_position -= glm::normalize(glm::cross(m_front, m_up)) * translationSpeed;
		}
		if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
			m_position += glm::normalize(glm::cross(m_front, m_up)) * translationSpeed;
		}
		
	}else {

		// // Translation
		// if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
		// 	m_position += m_front * translationSpeed;
		// }
		// if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
		// 	m_position -= m_front * translationSpeed;
		// }

		m_rotationSpeed = 0.5; 

		// Déplacement avant arriere
		if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
            m_position += glm::normalize(glm::vec3(m_front.x, 0.0f, m_front.z)) * translationSpeed;
        }
        if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
            m_position -= glm::normalize(glm::vec3(m_front.x, 0.0f, m_front.z)) * translationSpeed;
        }

		if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
			m_position -= glm::normalize(glm::cross(m_front, m_up)) * translationSpeed;
		}
		if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
			m_position += glm::normalize(glm::cross(m_front, m_up)) * translationSpeed;
		}

		// Rotation
		if (glfwGetKey(_window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			m_eulerAngle.y -= rotationSpeed;
			m_eulerAngle.y = Camera_Helper::clipAngle(glm::degrees(m_eulerAngle.y), 180);
			
		}
		if (glfwGetKey(_window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			m_eulerAngle.y += rotationSpeed;
			m_eulerAngle.y = Camera_Helper::clipAngle(glm::degrees(m_eulerAngle.y), 180);
		}
		if (glfwGetKey(_window, GLFW_KEY_UP) == GLFW_PRESS) {
			m_eulerAngle.x -= rotationSpeed;
			m_eulerAngle.x = Camera_Helper::clipAngle(glm::degrees(m_eulerAngle.x), 90);
		}
		if (glfwGetKey(_window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			m_eulerAngle.x += rotationSpeed;
			m_eulerAngle.x = Camera_Helper::clipAngle(glm::degrees(m_eulerAngle.x), 90);
			
		}


		

		// Modification hauteur
		if (glfwGetKey(_window, GLFW_KEY_Q) == GLFW_PRESS) {
            m_position.y -= translationSpeed;
        }
        if (glfwGetKey(_window, GLFW_KEY_E) == GLFW_PRESS) {
            m_position.y += translationSpeed;
        }

	}

    




}

void Camera::updateCameraRotation(){
	// Convertir les angles d'Euler en quaternion pour la rotation
	glm::quat pitchQuat = glm::angleAxis(m_eulerAngle.x, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::quat yawQuat = glm::angleAxis(m_eulerAngle.y, glm::vec3(0.0f, 1.0f, 0.0f));
    m_rotation = yawQuat * pitchQuat;


}

void Camera::updateCameraOrientation(){
	// Recalculer les vecteurs d'orientation
    m_front = glm::normalize(glm::rotate(m_rotation, glm::vec3(0.0f, 0.0f, -1.0f)));
    m_right = glm::normalize(glm::rotate(m_rotation, glm::vec3(1.0f, 0.0f, 0.0f)));
    m_up = glm::normalize(glm::cross(m_right, m_front));

}


void Camera::update(float _deltaTime, GLFWwindow* _window)
{
	updateInterface(_deltaTime);
	updateFreeInput(_deltaTime, _window);

	updateCameraRotation();
	updateCameraOrientation();

	Camera_Helper::computeFinalView(m_projectionMatrix, m_viewMatrix, m_position, m_rotation, m_fovDegree);
}





