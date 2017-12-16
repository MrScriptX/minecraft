#pragma once


#include <GL\glew.h>
#include <string>

class Basic_Texture
{
public:
	Basic_Texture();
	~Basic_Texture();

	void load(const std::string fileName);

	void bind();
	void unbind();

private:
	GLuint m_textureID;
};

