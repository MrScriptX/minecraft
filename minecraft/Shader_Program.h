#pragma once


#include <GL\glew.h>
#include "Shader_Loader.h"


class Shader_Program
{
public:
	Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	~Shader_Program();

	void bind();
	void unbind();

private:
	GLuint m_programID;

};


