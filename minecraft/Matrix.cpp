#include "Matrix.h"

#include "OpenGL_Context.h"

matrix4 createViewMatrix(const Camera & entity)
{
	matrix4 matrix;

	matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), { 1, 0, 0 });
	matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), { 0, 1, 0 });
	matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), { 0, 0, 1 });

	matrix = glm::translate(matrix, -entity.position);

	return matrix;
}

matrix4 createModelMatrix(const Entity & entity)
{
	matrix4 matrix;

	matrix = glm::translate(matrix, entity.position);

	matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), { 1, 0, 0 });
	matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), { 0, 1, 0 });
	matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), { 0, 0, 1 });

	return matrix;
}

matrix4 createProjectionMatrix()
{
	Display m_display;

	return glm::perspective(glm::radians(120.0f), (float)(m_display.width / m_display.height), 0.001f, 1000.0f);
}
