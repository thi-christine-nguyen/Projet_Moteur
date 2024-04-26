#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>

#define M_PI       3.14159265358979323846f   // pi

static glm::vec3 VEC_ZERO{ 0.f,0.f,0.f };
static glm::vec3 VEC_UP{ 0.f,1.f,0.f };
static glm::vec3 VEC_FRONT{ 0.f,0.f,1.f };
static glm::vec3 VEC_RIGHT{ 1.f,0.f,0.f };

enum class InterpolationType
{
    Linear,
    Cosine,
    Exponential,
    Logarithmic
};

class Camera_Helper
{
public: 
	static glm::vec3 quatToEuler(glm::quat _quat);
	static void computeFinalView(glm::mat4& _outProjectionMatrix, glm::mat4& _outviewMatrix, glm::vec3& _position, glm::quat _rotation, float _fovDegree);
    static glm::vec3 ProjectVectorOnPlane(const glm::vec3& _vectorToProject, const glm::vec3& _planeNormal);
    static float ClipAngle180(float _angle);
    static float clipAngle(float angle, float value); 
    static float Interpolation(float _ratio, InterpolationType _type);
};