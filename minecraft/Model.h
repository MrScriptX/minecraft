#pragma once


#include <GL\glew.h>
#include <vector>

class Model
{
public:
	Model(const std::vector<GLfloat> &vertexPosition);
	~Model();

	void bind();
	void unbind();

private:
	void addVBO(int dim, const std::vector<GLfloat>& data);

	std::vector<GLuint> m_buffers;
	GLuint m_vaoID = 0;

	GLuint m_vboCount = 0;
};

