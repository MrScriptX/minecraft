#pragma once


#include <stack>
#include "OpenGL_Context.h"
#include "Game_States.h"
#include "Playing_State.h"


class Application
{
public:
	Application();

	void gameLoop();
	void pushGameState(std::unique_ptr<Game_State> state);
	void popGameState();

private:
	std::stack<std::unique_ptr<Game_State>> m_states;
	OpenGL_Context m_display;

};

