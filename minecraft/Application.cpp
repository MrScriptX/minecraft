#include "Application.h"



Application::Application(): m_context(), m_window(sf::VideoMode(WIDTH, HEIGHT), "Cube Quest", sf::Style::Default, m_context.getSettings())
{
	glewInit();
	glViewport(0, 0, m_window.getSize().x, m_window.getSize().y);
}


void Application::gameLoop()
{
	while (m_Open)
	{
		m_window.clear();
		m_window.display();
		closeLoop();
	}

	m_window.close();
}

void Application::closeLoop()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Open = false;
		}
	}
}
