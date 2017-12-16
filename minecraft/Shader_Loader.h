#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <GL\glew.h>


GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
std::string get_SourceFile(const std::string& sourceFile);
GLuint compileShader(const GLchar* source, GLenum type);
GLuint createProgram(GLuint vertexID, GLuint fragmentID);