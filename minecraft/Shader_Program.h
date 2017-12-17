#pragma once


#include <GL\glew.h>
#include "Glm_Common.h"
#include "Shader_Loader.h"


class Shader_Program
{
public:
	Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	~Shader_Program();

	void bind();
	void unbind();

protected:
	virtual void get_UniformLocations() = 0;

	GLuint get_ID() const;
	void loadFloat(GLuint location, float value);
	void loadVector2(GLuint location, const vector2& vector);
	void loadMatrix4(GLuint location, const matrix4& matrix);

private:
	GLuint m_programID;

};



