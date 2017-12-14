#pragma once


#include <gl\glew.h>
#include <SFML\OpenGL.hpp>
#include <SFML\Graphics.hpp>


class OpenGL_Context
{
public:
	OpenGL_Context();
	~OpenGL_Context();

	sf::ContextSettings getSettings();

private:
	sf::ContextSettings m_settings;

};

