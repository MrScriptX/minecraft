#pragma once


#include "Render_Master.h"
#include "Game_States.h"
#include "Simple_Shader.h"
#include "Basic_Texture.h"
#include "Quad.h"
#include "Camera.h"


class Playing_State : public Game_State
{
public:
	Playing_State(Application* app);
	~Playing_State();

	void input(Camera& camera) override;
	void update(Camera& camera, float deltaTime) override;
	void draw(Render_Master& renderer) override;

private:
	Simple_Shader m_shader;
	Basic_Texture m_texture;
	Quad m_quad;
};

