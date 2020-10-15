#pragma once

#include "graphics/iscene.h"

class MainScene : public IScene
{
private:
public:
	MainScene() : IScene() {}
	~MainScene();

	void init() override;
	void resize(unsigned int width, unsigned int height) override;
	void update(double dt) override;
	void render() override;
};