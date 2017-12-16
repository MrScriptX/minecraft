#include "OpenGL_Context.h"



OpenGL_Context::OpenGL_Context()
{
	m_settings.depthBits         = 24;
	m_settings.majorVersion      = 4;
	m_settings.minorVersion      = 6;

	m_window.window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_window.width, m_window.height), "Cube Quest", sf::Style::Close, m_settings);

	glewInit();
	glViewport(0, 0, m_window.width, m_window.height);
}


OpenGL_Context::~OpenGL_Context()
{

}

void OpenGL_Context::close()
{
	sf::Event event;
	while (m_window.window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.window->close();
		}
	}
}

void OpenGL_Context::clear()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void OpenGL_Context::run()
{
	while (m_window.window->isOpen())
	{
		clear();
		m_window.window->display();
		close();
	}
}
