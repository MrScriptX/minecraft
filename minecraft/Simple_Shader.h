#pragma once


#include "Shader_Program.h"

class Simple_Shader: public Shader_Program
{
public:
	Simple_Shader();
	~Simple_Shader();

	void setTime(float time);
	void setViewMatrix(const matrix4& matrix);
	void setModelMatrix(const matrix4& matrix);
	void setProjMatrix(const matrix4& matrix);

private:
	void get_UniformLocations() override;

	GLuint m_locationTime = 0;
	GLuint m_locationViewMatrix = 0;
	GLuint m_locationModelMatrix = 0;
	GLuint m_locationProjectionMatrix = 0;
};

