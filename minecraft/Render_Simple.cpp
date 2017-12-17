#include "Render_Simple.h"

#include "Matrix.h"


Render_Simple::Render_Simple()
{
}


Render_Simple::~Render_Simple()
{
}

void Render_Simple::draw(const Quad & quad)
{
	m_quads.push_back(&quad);
}

void Render_Simple::update(const Camera & camera)
{
	m_shader.bind();
	m_shader.setTime(m_clock.getElapsedTime().asSeconds());

	m_shader.setViewMatrix(createViewMatrix(camera));

	for ( auto &quad : m_quads)
	{
		prepare(*quad);
		glDrawElements(GL_TRIANGLES, quad->get_Model().get_indicesCount(), GL_UNSIGNED_INT, nullptr);
	}

	m_quads.clear();
}

void Render_Simple::prepare(const Quad &quad)
{
	quad.get_Model().bind();
	m_shader.setModelMatrix(createModelMatrix(quad));
}
