#include "main_scene.h"

#include <iostream>
#include <imgui.h>

MainScene::~MainScene()
{

}

void MainScene::init()
{

}

void MainScene::resize(unsigned int width, unsigned int height)
{

}

void MainScene::update(double dt)
{
    std::cout << "Elapsed: " << dt << " s\n";
}

void MainScene::render()
{
    ImGui::Begin("Demo window");
    ImGui::Button("Hello!");
    ImGui::End();

    ImGui::Begin("Demo window 2");
    ImGui::Button("Hello!");
    ImGui::End();
}