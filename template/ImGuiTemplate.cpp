// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "ImGui.hpp"

const double M_PI = 3.14159265359;

//---------------------------------------------------------------

int w = 1000;
int h = 1000;
float center_x = (float)w / 2.0f;
float center_y = (float)h / 2.0f;
int starsN = 200;

//---------------------------------------------------------------
float randomInit()
{
	std::random_device device;
	std::mt19937 engine(device());
	// std::uniform_real_distribution<float> dist(0, (float)w);
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


//---------------------------------------------------------------

void starfield()
{
	// ImGui
	const char* title = "Starfield simulation";
	UseImGui starfieldGui(title);

	//GLFWwindow* window = initImgui(w, h, title);

	// colors
	ImVec4 clear_color = ImVec4(0.0f  , 0.0f  , 0.0f  , 1.00f);
	ImVec4 dot_color   = ImVec4(255.0f, 255.0f, 255.0f, 1.00f);

	// stars for simulations
	std::vector<Star> stars;
	for (int ii = 0; ii < starsN; ii++)
	{
		stars.emplace_back(Star());
	}

	// starfield simumlation settings ImGui
	ImGuiWindowFlags window_flags = 0;
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2((float)w, (float)h), ImGuiCond_FirstUseEver);
	window_flags |= ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_NoCollapse;
	window_flags |= ImGuiWindowFlags_NoBackground;
	window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;

	// Simulate and show with ImGui
	while (!glfwWindowShouldClose(starfieldGui.window))
	{
		// starfield simumlation calculation
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		for (auto& s : stars)
		{
			s.move();
			draw_list->AddCircleFilled({ s.x, s.y }, s.r, ImColor(dot_color));
		}
		for (auto& s : stars)
		{
			s.rotate(1.0f);
		}
		// Simulation speed
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		
		starfieldGui.Update();
	}
}


/// <summary>
/// ImGui Template 
/// </summary>
/// <returns>int</returns>
int main()
{

	starfield();

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

