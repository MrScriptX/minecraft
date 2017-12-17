#pragma once


#include <cmath>
#include "Glm_Common.h"
#include "Entity.h"
#include <SFML\Window\Keyboard.hpp>

class Camera: public Entity
{
public:
	Camera();
	~Camera();

	void input(float deltaTime);
};

