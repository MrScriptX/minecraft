#pragma once

class Render_Master;
class Application;
class Camera;

class Game_State
{
public:
	Game_State(Application* app);

	virtual void input(Camera& camera) = 0;
	virtual void update(Camera& camera, float deltaTime) = 0;
	virtual void draw(Render_Master& renderer) = 0;

protected:
	Application* m_app;
};

