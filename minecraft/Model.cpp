#include "Model.h"



Model::Model(const std::vector<GLfloat> &vertexPosition)
{
	glGenBuffers(1, &m_vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, m_vaoID);
	
	addVBO(2, vertexPosition);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


Model::~Model()
{
	glDeleteVertexArrays(1, &m_vaoID);

	glDeleteBuffers(m_buffers.size(), m_buffers.data());
}

void Model::bind()
{
	glBindVertexArray(m_vaoID);
}

void Model::unbind()
{
	glBindVertexArray(0);
}

void Model::addVBO(int dim, const std::vector<GLfloat>& data)
{
	GLuint vboID;

	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), data.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(m_vboCount, dim, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(m_vboCount++);

	m_buffers.push_back(vboID);

}
