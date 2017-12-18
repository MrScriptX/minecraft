#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::input(float deltaTime)
{
	Vector3 change = { 0, 0, 0 };
	float speed = 2.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		change.x += -sin(glm::radians(rotation.y)) * speed;
		change.z += -cos(glm::radians(rotation.y)) * speed;
	}

	position += change * deltaTime;
}
