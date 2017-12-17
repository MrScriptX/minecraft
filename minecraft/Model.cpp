#include "Model.h"



Model::Model(const std::vector<GLfloat> &vertexPosition, const std::vector<GLfloat> &textureCoord, const std::vector<GLuint> &indices): m_indices(indices.size())
{
	glGenBuffers(1, &m_vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, m_vaoID);
	
	addVBO(3, vertexPosition);
	addVBO(2, textureCoord);
	addEBO(indices);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


Model::~Model()
{
	glDeleteVertexArrays(1, &m_vaoID);

	glDeleteBuffers(m_buffers.size(), m_buffers.data());
}

void Model::bind() const
{
	glBindVertexArray(m_vaoID);
}

void Model::unbind() const
{
	glBindVertexArray(0);
}

GLuint Model::get_indicesCount() const
{
	return m_indices;
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

void Model::addEBO(const std::vector<GLuint>& indices)
{
	GLuint ebo;
	
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);

	m_buffers.push_back(ebo);
}
