#pragma once


#include <GL\glew.h>
#include <vector>

class Model
{
public:
	Model(const std::vector<GLfloat> &vertexPosition, const std::vector<GLfloat> &textureCoord, const std::vector<GLuint> &indices);
	~Model();

	void bind() const;
	void unbind() const;

	GLuint get_indicesCount() const;

private:
	void addVBO(int dim, const std::vector<GLfloat>& data);
	void addEBO(const std::vector<GLuint> &indices);

	std::vector<GLuint> m_buffers;
	GLuint m_vaoID = 0;

	GLuint m_vboCount = 0;
	GLuint m_indices = 0;
};

