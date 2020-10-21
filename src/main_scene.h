#pragma once

#include <imgui.h>
#include "graphics/iscene.h"
#include "graphics/shader.h"
#include "graphics/renderer.h"
#include "graphics/model.h"
#include "graphics/framebuffer.h"

class MainScene : public IScene
{
private:
	ImGuiWindowFlags layout_flags;
	Shader* shader;
	Renderer* renderer;
	Model* model, *model2;
	Framebuffer* fb;

public:
	MainScene() : IScene() {}
	~MainScene();

	void init() override;
	void input() override;
	void update(double dt) override;
	void render() override;
	void resize(unsigned int width, unsigned int height) override;
};