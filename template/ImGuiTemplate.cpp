// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "ImGui.hpp"

/// <summary>
/// ImGui Template 
/// </summary>
/// <returns>int</returns>
int main()
{	
	///////////////////////////////////////////////
	// Create ImGui object
	UseImGui starfieldGui("Starfield simulation");
	starfieldGui.initStarfield();
	// Simulate and show with ImGui
	while (!glfwWindowShouldClose(starfieldGui.window))
	{
		starfieldGui.starfield();
	}
	starfieldGui.Shutdown();

	///////////////////////////////////////////////
	// Create ImGui object
	UseImGui myimgui;
	cout << "ImGui running" << endl;
	// ImGui update
	while (!glfwWindowShouldClose(myimgui.window)) {
		myimgui.Update();
	}
	myimgui.Shutdown();
	cout << "Shutdown sucessfull";
	return 0;
}

