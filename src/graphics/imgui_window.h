#pragma once

#include <string>

class ImGuiWindow
{
private:
	const std::string title;

public:
	ImGuiWindow(const std::string& title);
	~ImGuiWindow();


};