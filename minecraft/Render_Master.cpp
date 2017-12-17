#include "Render_Master.h"



Render_Master::Render_Master(): m_display()
{
}


Render_Master::~Render_Master()
{
}

void Render_Master::clear()
{
	m_display.clear();
}

void Render_Master::update(const Camera& camera)
{
	m_SimpleRenderer.update(camera);
	m_display.display();
	m_display.close();
}

void Render_Master::draw(const Quad & model)
{
	m_SimpleRenderer.draw(model);
}

bool Render_Master::isOpen()
{
	return m_display.get_IsOpen();
}