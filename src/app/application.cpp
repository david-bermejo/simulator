#include "application.h"
#include "../utils/timer.h"

Application::Application(unsigned int width, unsigned int height, const std::string& title)
	: window(width, height, title), scene(nullptr) {}

Application::~Application() {}

void Application::setScene(IScene* scene)
{
	this->scene = scene;
	this->scene->init();
}

void Application::run()
{
	Timer timer;
	Timer timer_fps;
	unsigned int fps = 0;

	while (!window.closed())
	{
		window.pollEvents();

		const double dt = timer.elapsed();
		timer.reset();
		scene->update(dt);

		renderer.begin();
		scene->render();
		renderer.end();

		fps++;
		if (timer_fps.elapsed() > 1.0) {
			timer_fps.reset();
			window.displayFPS(fps);
			fps = 0;
		}

		window.update();
	}
}