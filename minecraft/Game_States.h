#pragma once

class Application;

class Game_State
{
public:
	Game_State(Application* app);

	virtual void input() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

protected:
	Application* m_app;
};

