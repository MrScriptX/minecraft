#include "Playing_State.h"



Playing_State::Playing_State(Application* app): Game_State(app), m_model({	0.5,	0.5,
																			-0.5,	0.5,
																			-0.5,	-0.5,
																			-0.5,	-0.5,
																			0.5,	-0.5,
																			0.5,	0.5})
{

}


Playing_State::~Playing_State()
{
}

void Playing_State::input()
{
}

void Playing_State::update()
{
}

void Playing_State::draw()
{
	m_model.bind();
	
	glDrawArrays(GL_TRIANGLES, 0, 6);

	m_model.unbind();
}
