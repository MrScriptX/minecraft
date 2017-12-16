#pragma once

 
#include <memory>
#include <gl\glew.h>
#include <SFML\OpenGL.hpp>
#include <SFML\Graphics.hpp>


typedef struct display
{
	constexpr static int width = 1280;
	constexpr static int height = 720;

	std::unique_ptr<sf::RenderWindow> window;

} Display;

class OpenGL_Context
{
public:
	OpenGL_Context();
	~OpenGL_Context();

	void display();
	void close();
	void clear();

	bool get_IsOpen();

private:
	sf::ContextSettings m_settings;
	Display m_window;

};

