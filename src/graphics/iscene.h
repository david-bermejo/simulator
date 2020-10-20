#pragma once

class IScene
{
public:
	IScene() = default;
	virtual void init() = 0;
	virtual void input() = 0;
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual void resize(unsigned int width, unsigned int height) = 0;
};