#include "Simple_Shader.h"

#include "Matrix.h"

Simple_Shader::Simple_Shader(): Shader_Program("Simple_Vertex", "Simple_Fragment")
{
	get_UniformLocations();

	bind();
	loadMatrix4(m_locationProjectionMatrix, createProjectionMatrix());
	unbind();
}


Simple_Shader::~Simple_Shader()
{
}

void Simple_Shader::setTime(float time)
{
	loadFloat(m_locationTime, time);
}

void Simple_Shader::setViewMatrix(const matrix4 & matrix)
{
	loadMatrix4(m_locationViewMatrix, matrix);
}

void Simple_Shader::setModelMatrix(const matrix4 & matrix)
{
	loadMatrix4(m_locationModelMatrix, matrix);
}

void Simple_Shader::setProjMatrix(const matrix4 & matrix)
{
	loadMatrix4(m_locationProjectionMatrix, matrix);
}

void Simple_Shader::get_UniformLocations()
{
	m_locationTime = glGetUniformLocation(get_ID(), "time");

	m_locationViewMatrix = glGetUniformLocation(get_ID(), "viewMatrix");
	m_locationModelMatrix = glGetUniformLocation(get_ID(), "modelMatrix");
	m_locationProjectionMatrix = glGetUniformLocation(get_ID(), "projectionMatrix");
}
