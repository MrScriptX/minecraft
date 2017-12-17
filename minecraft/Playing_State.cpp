#include "Playing_State.h"

#include <SFML\System\Clock.hpp>



Playing_State::Playing_State(Application* app): Game_State(app)
{
	m_texture.load("grass");
	m_texture.bind();

	m_quad.position.z = -8;
}


Playing_State::~Playing_State()
{
}

void Playing_State::input(Camera& camera)
{
}

void Playing_State::update(Camera& camera, float deltaTime)
{
	camera.input(deltaTime);
}

void Playing_State::draw(Render_Master& renderer)
{
	renderer.draw(m_quad);
}
