// ImGuiTemplate.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <random>
#include <thread>
#include <Eigen/Dense>


// Common name space for the project
using namespace std;

// ImGui and its dependencies
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

// openGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// implot
#include <implot.h>

///////////////////////////////////////////
//  Enum`s
///////////////////////////////////////////

enum resolution
{
    windowWidth = 1920,
    windowHeight = 1080
};

/*
// Suppress Visual Studio warnings
#ifdef _MSC_VER
#pragma warning (disable: 4127)     // condition expression is constant
#pragma warning (disable: 4996)     // 'This function or variable may be unsafe': strcpy, strdup, sprintf, vsnprintf, sscanf, fopen
#pragma warning (disable: 26451)    // [Static Analyzer] Arithmetic overflow : Using operator 'xxx' on a 4 byte value and then casting the result to an 8 byte value. Cast the value to the wider type before calling operator 'xxx' to avoid overflow(io.2).
#endif
*/


const double M_PI = 3.14159265359;

//---------------------------------------------------------------

int w = 1000;
int h = 1000;
float center_x = (float)w / 2.0f;
float center_y = (float)h / 2.0f;


//---------------------------------------------------------------
float randomInit()
{
	std::random_device device;
	std::mt19937 engine(device());
	std::uniform_real_distribution<float> dist(0.0f, (float)w);
	return dist(engine);
}

//---------------------------------------------------------------
Eigen::Matrix<float, 3, 3> RotZ(float ang)
{

	float c = std::cos(((float)M_PI / 180) * ang);
	float s = std::sin(((float)M_PI / 180) * ang);

	Eigen::Matrix<float, 3, 3> Rz;
	Rz << c, -s, 0.0f,
		s, c, 0.0f,
		0.0f, 0.0f, 0.0f;
	return Rz;
}

//---------------------------------------------------------------

struct Star
{
	float x;
	float y;
	float z;
	float r;

	Star()
	{
		this->x = randomInit();
		this->y = randomInit();
		this->z = 0.0f;
		this->r = 1.0f;
	}

	void move()
	{
		this->z = this->z + 1.0f;
		if (this->y > h || this->x > w || this->y < 0 || this->x < 0)
		{
			this->x = randomInit();
			this->y = randomInit();
			this->z = 0.0f;
			this->r = 1.0f;
		}
		else
		{
			this->x = (this->x - (float)w / 2.0f) * 1.05f + (float)w / 2.0f;
			this->y = (this->y - (float)h / 2.0f) * 1.05f + (float)h / 2.0f;
			this->r = this->r + 0.1f;
		}
	}

	void rotate(float ang)
	{
		Eigen::Matrix<float, 3, 1> C;
		C << center_x, center_y, 0.0f;

		Eigen::Matrix<float, 3, 1> P;
		P << this->x, this->y, 0.0f;

		Eigen::Matrix<float, 3, 1> Pr;

		Pr = RotZ(ang) * (P - C) + C;
		this->x = Pr(0, 0);
		this->y = Pr(1, 0);
	}
};



