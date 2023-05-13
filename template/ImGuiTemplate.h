// ImGuiTemplate.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>

#pragma warning(disable : 4996)

// Verweisen Sie hier auf zusätzliche Header, die Ihr Programm erfordert
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


// openGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//implot
#include <implot.h>


class UseImGui {
public:
	void Init(GLFWwindow* window, const char* glsl_version);
	void NewFrame();
	virtual void Update();
	void Render();
	void Shutdown();
};