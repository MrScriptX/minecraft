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

} display;

class OpenGL_Context
{
public:
	OpenGL_Context();
	~OpenGL_Context();

	void run();

private:
	void close();
	void clear();

	sf::ContextSettings m_settings;
	display m_window;

};

