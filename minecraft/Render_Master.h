#pragma once


#include "Render_Simple.h"
#include "Quad.h"
#include "OpenGL_Context.h"
#include "Camera.h"

class Render_Master
{
public:
	Render_Master();
	~Render_Master();

	void clear();
	void update(const Camera& camera);
	void draw(const Quad& model);
	bool isOpen();

protected:


private:
	Render_Simple m_SimpleRenderer;
	OpenGL_Context m_display;

};

