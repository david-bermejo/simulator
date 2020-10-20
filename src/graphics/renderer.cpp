#include "renderer.h"

#include <GL/glew.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <GLFW/glfw3.h>

Renderer::Renderer(Shader* shader)
	: v_width(0), v_height(0), shader(shader)
{
	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glFrontFace(GL_CW);
}

Renderer::~Renderer() {}

void Renderer::begin()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->begin();
}

void Renderer::render(Model* model)
{
	glBindVertexArray(model->vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, model->elements, GL_UNSIGNED_INT, nullptr);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}

void Renderer::end()
{
	glfwGetFramebufferSize(glfwGetCurrentContext(), (int*)&v_width, (int*)&v_height);
	glViewport(0, 0, v_width, v_height);
	
	shader->end();
}