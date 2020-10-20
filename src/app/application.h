#pragma once

#include <string>
#include "../graphics/iscene.h"
#include "../graphics/window.h"

class Application
{
private:
	IScene* scene;
	Window window;

public:
	Application(unsigned int width, unsigned int height, const std::string& title);
	~Application();

	void setScene(IScene* scene);
	void run();
};