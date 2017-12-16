#include "Simple_Shader.h"



Simple_Shader::Simple_Shader(): Shader_Program("Simple_Vertex", "Simple_Fragment")
{
	bindAttributes();
}


Simple_Shader::~Simple_Shader()
{
}

void Simple_Shader::bindAttributes()
{
	bindAttribute(0, "inVertexPosition");
}
