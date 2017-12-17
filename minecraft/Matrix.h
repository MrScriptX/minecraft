#pragma once


#include"Entity.h"
#include "Camera.h"

matrix4 createViewMatrix(const Camera& entity);
matrix4 createModelMatrix(const Entity& entity);
matrix4 createProjectionMatrix();