#include "Shader_Program.h"



Shader_Program::Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile): m_programID(loadShader(vertexShaderFile, fragmentShaderFile))
{

}


Shader_Program::~Shader_Program()
{
	glDeleteProgram(m_programID);
}

void Shader_Program::bind()
{
	glUseProgram(m_programID);
}

void Shader_Program::unbind()
{
	glUseProgram(0);
}

GLuint Shader_Program::get_ID() const
{
	return m_programID;
}

void Shader_Program::loadFloat(GLuint location, float value)
{
	glUniform1f(location, value);
}

void Shader_Program::loadVector2(GLuint location, const vector2 & vector)
{
	glUniform2f(location, vector.x, vector.y);
}

void Shader_Program::loadMatrix4(GLuint location, const matrix4 & matrix)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}


