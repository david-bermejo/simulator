#pragma once

#include "model.h"
#include "shader.h"

class Renderer
{
private:
	unsigned int v_width;
	unsigned int v_height;
	Shader* shader;

public:
	Renderer(Shader* shader);
	~Renderer();

	void begin();
	void render(Model* model);
	void end();
};