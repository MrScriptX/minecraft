#pragma once


#include "Shader_Program.h"

class Simple_Shader: public Shader_Program
{
public:
	Simple_Shader();
	~Simple_Shader();

private:
	void bindAttributes() override;
};

