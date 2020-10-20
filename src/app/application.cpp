#include "application.h"
#include "../utils/timer.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

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
		scene->input();

		const double dt = timer.elapsed();
		timer.reset();
		scene->update(dt);

		// Begin rendering ImGui
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		scene->render();

		// Finish rendering ImGui
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		fps++;
		if (timer_fps.elapsed() > 1.0) {
			timer_fps.reset();
			window.displayFPS(fps);
			fps = 0;
		}

		window.update();
	}
}