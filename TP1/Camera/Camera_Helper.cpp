#include <TP1/Camera/Camera_Helper.hpp>
#include <iostream>
#include <vector>

glm::vec3 Camera_Helper::ProjectVectorOnPlane(const glm::vec3& _vectorToProject, const glm::vec3& _planeNormal)
{
    return _vectorToProject - glm::dot(_vectorToProject, _planeNormal) * _planeNormal;
}

float Camera_Helper::ClipAngle180(float _angle)
{
    while (_angle >= 180.0f)
        _angle -= 360.0f;
    while (_angle < -180.0f)
        _angle += 360.0f;

    return fmod(_angle, 180);
}

float Camera_Helper::clipAngle(float angle, float value)
{
    
   // Limiter l'angle entre -value et value
    angle = glm::clamp(angle, -value, value);
    return glm::radians(angle);
}

float Camera_Helper::Interpolation(float _ratio, InterpolationType _type)
{
    switch (_type)
    {
    case InterpolationType::Linear:
        return _ratio; // Interpolation linéaire, pas de modification
    case InterpolationType::Cosine:
        return (1 - cos(_ratio * M_PI)) / 2; // Interpolation cosine
    case InterpolationType::Exponential:
        return exp(_ratio); // Interpolation exponentielle
    case InterpolationType::Logarithmic:
        return log(_ratio + 1); // Interpolation logarithmique
    default:
        return _ratio; // Par défaut, pas de modification
    }
}

glm::vec3 Camera_Helper::quatToEuler(glm::quat _quat)
{
	// Opengl quat to euler function give yaw betweel -90 and 90
	// If you want correct pitch and yaw you can use this 
	// Src http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/index.htm
	// But roll will be bewteen -90 and 90 here

	glm::vec3 eulerAngles;

	float test = _quat.x * _quat.y + _quat.z * _quat.w;

	if (test > 0.499f) { // singularity at north pole
		eulerAngles.y = 2.f * atan2(_quat.x, _quat.w);
		eulerAngles.z = M_PI / 2.f;
		eulerAngles.x = 0.f;
		return eulerAngles;
	}
	if (test < -0.499f) { // singularity at south pole
		eulerAngles.y = -2.f * atan2(_quat.x, _quat.w);
		eulerAngles.z = -M_PI / 2.f;
		eulerAngles.x = 0.f;
		return eulerAngles;
	}
	float sqx = _quat.x * _quat.x;
	float sqy = _quat.y * _quat.y;
	float sqz = _quat.z * _quat.z;


	eulerAngles.y = atan2(2.f * _quat.y * _quat.w - 2.f * _quat.x * _quat.z, 1.f - 2.f * sqy - 2.f * sqz);
	eulerAngles.z = asin(2.f * test);
	eulerAngles.x = atan2(2.f * _quat.x * _quat.w - 2.f * _quat.y * _quat.z, 1.f - 2.f * sqx - 2.f * sqz);

	return eulerAngles;
}



void Camera_Helper::computeFinalView(glm::mat4& _outProjectionMatrix, glm::mat4& _outviewMatrix, glm::vec3& _position, glm::quat _rotation, float _fovDegree)
{
	// Projection matrix : FOV, 4:3 ratio, display range : 0.1 unit <-> 100 units
	_outProjectionMatrix = glm::perspective(glm::radians(_fovDegree), 4.0f / 3.0f, 0.1f, 200.0f);

	const glm::vec3 front = normalize(_rotation* VEC_FRONT);
	const glm::vec3 up = normalize(_rotation * VEC_UP);

	// Camera matrix
	_outviewMatrix = glm::lookAt(_position, _position + front, up);
}