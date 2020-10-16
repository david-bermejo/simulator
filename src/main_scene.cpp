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
    
}

void MainScene::render()
{
    ImGui::Begin("Demo window");
    if (ImGui::BeginTabBar("blah"))
    {
        if (ImGui::BeginTabItem("Video"))
        {
            ImGui::Button("Save");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Music"))
        {
            ImGui::Button("Upload");
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    ImGui::End();

    ImGui::Begin("Demo window 2");
    ImGui::Button("Hello!");
    ImGui::End();
}