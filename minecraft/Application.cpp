#include "Application.h"



Application::Application(): m_renderer()
{
	pushGameState(std::make_unique<Playing_State>(this));
}

void Application::gameLoop()
{
	sf::Clock clock;

	while (m_renderer.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		m_renderer.clear();

		m_states.top()->input(m_camera);
		m_states.top()->update(m_camera, deltaTime);
		m_states.top()->draw(m_renderer);

		m_renderer.update(m_camera);//check for close in update
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
