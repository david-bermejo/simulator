#pragma once

#define GLEW_STATIC

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
private:
	unsigned int width;
	unsigned int height;
	std::string title;
	GLFWwindow* window;

private:
	void init();

public:
	Window(unsigned int width, unsigned int height, const std::string& title);
	~Window();

	void pollEvents();
	void update();
	bool closed();

	GLFWwindow* context() const { return window; }
	void displayFPS(unsigned int fps);
};