#pragma once


#include "Game_States.h"
#include "Model.h"


class Playing_State : public Game_State
{
public:
	Playing_State(Application* app);
	~Playing_State();

	void input() override;
	void update() override;
	void draw() override;

private:
	Model m_model;
};

