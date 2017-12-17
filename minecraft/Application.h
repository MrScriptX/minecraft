#pragma once


#include <stack>
#include "Game_States.h"
#include "Playing_State.h"
#include "Render_Master.h"
#include "Camera.h"


class Application
{
public:
	Application();

	void gameLoop();
	void pushGameState(std::unique_ptr<Game_State> state);
	void popGameState();

private:
	std::stack<std::unique_ptr<Game_State>> m_states;
	Render_Master m_renderer;
	Camera m_camera;

};

