#include "Playing_State.h"

//regroup vect in a struct call object
std::vector<GLfloat> vertexPosition =
{	0.5,	0.5,
	-0.5,	0.5,
	-0.5,	-0.5,
	0.5,	-0.5,
};

std::vector<GLfloat> textureCoord =
{
	1.0, 1.0,
	0.0, 1.0,
	0.0, 0.0,
	1.0, 0.0,
};

std::vector<GLuint> indices =
{
	0, 1, 2,
	2, 3, 0
};

Playing_State::Playing_State(Application* app): Game_State(app), m_model(vertexPosition, textureCoord, indices)
{
	m_texture.load("grass");
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
	m_shader.bind();
	m_model.bind();
	m_texture.bind();
	
	glDrawElements(GL_TRIANGLES, m_model.get_indicesCount(), GL_UNSIGNED_INT, nullptr);

	m_texture.unbind();
	m_model.unbind();
	m_shader.unbind();
}
