#pragma once

#include <GL/glew.h>
#include "shader.h"

class Framebuffer
{
public:
	unsigned int width, height;
	GLuint fbo, ms_fbo;
	GLuint tex, ms_tex;
	GLuint dbo, ms_dbo;

public:
	Framebuffer() = default;
	Framebuffer(unsigned int width, unsigned int height);
	~Framebuffer();

	void begin();
	void end();
};