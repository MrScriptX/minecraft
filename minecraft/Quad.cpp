#include "Quad.h"

#include <vector>


std::vector<GLfloat> vertexPosition =
{ 
	0.5,	0.5,	0,
	-0.5,	0.5,	0,
	-0.5,	-0.5,	0,
	0.5,	-0.5,	0
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

Quad::Quad(): m_model(vertexPosition, textureCoord, indices)
{

}

const Model & Quad::get_Model() const
{
	return m_model;
}
