#include "Application.h"



Application::Application(): m_display()
{
	pushGameState(std::make_unique<Playing_State>(this));
}

void Application::gameLoop()
{
	while (m_display.get_IsOpen())
	{
		m_display.clear();

		m_states.top()->input();
		m_states.top()->update();
		m_states.top()->draw();

		m_display.display();
		m_display.close();
	}
}

void Application::pushGameState(std::unique_ptr<Game_State> state)
{
	m_states.push(std::move(state));
}

void Application::popGameState()
{
	m_states.pop();
}
