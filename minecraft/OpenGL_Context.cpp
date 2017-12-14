#include "OpenGL_Context.h"



OpenGL_Context::OpenGL_Context()
{
	m_settings.depthBits         = 24;
	m_settings.majorVersion      = 4;
	m_settings.minorVersion      = 6;
	m_settings.antialiasingLevel = 0;
}


OpenGL_Context::~OpenGL_Context()
{

}

sf::ContextSettings OpenGL_Context::getSettings()
{
	return m_settings;
}
