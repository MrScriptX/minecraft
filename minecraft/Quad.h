#pragma once

#include "Entity.h"
#include "Model.h"


class Quad : public Entity
{
public:
	Quad();

	const Model& get_Model() const;

private:
	Model m_model;

};