#pragma once


#include "Settings.h"
#include "OpenGL_Context.h"


class Application
{
public:
	Application();

	void gameLoop();
	void closeLoop();

private:
	sf::RenderWindow m_window;
	OpenGL_Context   m_context;

	bool m_Open = true;

};

