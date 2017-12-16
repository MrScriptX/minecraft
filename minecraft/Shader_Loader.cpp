#include "Shader_Loader.h"



GLuint loadShader(const std::string & vertexShaderFile, const std::string & fragmentShaderFile)
{
	std::string vertexSource = get_SourceFile(vertexShaderFile);
	std::string fragmentSource = get_SourceFile(fragmentShaderFile);

	GLuint vertexShaderID = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
	GLuint fragmentShaderID = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

	GLuint programID = createProgram(vertexShaderID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return programID;
}

std::string get_SourceFile(const std::string& sourceFile)
{
	std::string source;
	std::stringstream stringStream;
	std::ifstream file("Data/Shaders/" + sourceFile + ".glsl");

	if (!file)
	{
		throw std::runtime_error("Shader file couldn't be open: " + sourceFile);
	}

	stringStream << file.rdbuf();
	source = stringStream.str();

	return source;
}

GLuint compileShader(const GLchar * source, GLenum type)
{
	GLuint ID = glCreateShader(type);

	glShaderSource(ID, 1, &source, nullptr);
	glCompileShader(ID);

	GLint compileSuccess;
	GLchar infoLog[512];

	glGetShaderiv(ID, GL_COMPILE_STATUS, &compileSuccess);

	if (compileSuccess == 0)
	{
		glGetShaderInfoLog(ID, 512, nullptr, infoLog);
		throw std::runtime_error("Failed to compile shaders: " + std::string(infoLog));
	}

	return ID;
}

GLuint createProgram(GLuint vertexID, GLuint fragmentID)
{
	GLuint ID = glCreateProgram();

	glAttachShader(ID, vertexID);
	glAttachShader(ID, fragmentID);

	glLinkProgram(ID);

	return ID;
}