// ImGuiTemplate.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>

#include <fstream>
#include <iostream>
#include <cstdlib>
//#include <unistd.h>

#include <array>
#include <vector>
#include <list>
#include <map>
#include <stack>

#include <algorithm>
#include <math.h>
#include <random>

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

#define M_PI = 3.14159265358979323846264338327950288419716939937510

// Visual Studio warnings
#ifdef _MSC_VER
#pragma warning (disable: 4127)     // condition expression is constant
#pragma warning (disable: 4996)     // 'This function or variable may be unsafe': strcpy, strdup, sprintf, vsnprintf, sscanf, fopen
#pragma warning (disable: 26451)    // [Static Analyzer] Arithmetic overflow : Using operator 'xxx' on a 4 byte value and then casting the result to an 8 byte value. Cast the value to the wider type before calling operator 'xxx' to avoid overflow(io.2).
#endif


///