#pragma once

#include <vector>
#include <SFML\System\Clock.hpp>
#include "Quad.h"
#include "Simple_Shader.h"
#include "Camera.h"


class Render_Simple
{
public:
	Render_Simple();
	~Render_Simple();

	void draw(const Quad & quad);
	void update(const Camera & camera);

private:
	void prepare(const Quad& quad);

	std::vector<const Quad*> m_quads;
	Simple_Shader m_shader;
	sf::Clock m_clock;

};

