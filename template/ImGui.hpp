#include "header.h"

/// <summary>
/// glfw error callback
/// </summary>
/// <param name="error"></param>
/// <param name="description"></param>
static void glfw_error_callback(int error, const char* description) {
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

/// <summary>
/// ImGui Window creation
/// </summary>
class UseImGui 
{
	const char* glsl_version = "#version 150";
	const char* title = "Title";

	// colors
	ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);
	ImVec4 dot_color = ImVec4(255.0f, 255.0f, 255.0f, 1.00f);

	// stars for simulations
	std::vector<Star> stars;

	// starfield simumlation settings ImGui
	ImGuiWindowFlags window_flags = 0;

public:

	GLFWwindow* window;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	UseImGui(const char* title = "Example")
	{
		// Setup window
			// Setup window
		glfwSetErrorCallback(glfw_error_callback);
		if (!glfwInit())
		{
			throw("errot in: glfwInit");
			cout << "errot in: glfwInit";
		}

		// GL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		// Create window with graphics context
		window = glfwCreateWindow(windowWidth, windowHeight, title, NULL, NULL);

		glfwMakeContextCurrent(window);
		glfwSwapInterval(1); // Enable vsync

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  // tie window context to glad's opengl funcs
			throw("Unable to context to OpenGL");

		int screen_width, screen_height;
		glfwGetFramebufferSize(window, &screen_width, &screen_height);
		glViewport(0, 0, screen_width, screen_height);
		Init();
	}

	/// <summary>
	/// setup GLFWwindow*, enable keyboard and gamepad controls and platform/renderer bindings 
	/// </summary>
	/// <param name="window"></param>
	/// <param name="glsl_version"></param>
	void Init() {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImPlot::CreateContext();

		// Include controls
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		
		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);
		ImGui::StyleColorsDark();
	}

	void NewFrame() {
		// feed inputs to dear imgui, start new frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	};
	virtual void Update() {
		// clear content
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		NewFrame();

		// start to add ImGui content 
		ImGui::Begin("CustomImGui Hello, world!");              // Create a window called "Hello, world!" and append into it.
		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		ImPlot::ShowDemoWindow();
		ImGui::End(); // end of content
		Render();
	}
	void Render() {
		// Render dear imgui into screen
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
	}

	void Shutdown() {
		// Cleanup
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImPlot::DestroyContext();
		ImGui::DestroyContext();
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void initStarfield(int starsN = 200)
	{
		
		for (int ii = 0; ii < starsN; ii++)
		{
			stars.emplace_back(Star());
		}
		// starfield simumlation settings ImGui
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2((float)w, (float)h), ImGuiCond_FirstUseEver);
		window_flags |= ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoResize;
		window_flags |= ImGuiWindowFlags_NoCollapse;
		window_flags |= ImGuiWindowFlags_NoBackground;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;

	}

	void starfield(int delay = 20)
	{
		/////////////////////////////////
		// prepare for new Frame
		glfwPollEvents();
		// clear content
		glClear(GL_COLOR_BUFFER_BIT);

		/////////////////////////////////
		// Frame
		NewFrame();
		ImGui::Begin("Simulation", nullptr, window_flags);

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
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));

		ImGui::End(); // end of content

		/////////////////////////////////
		// Rendering
		Render();
		
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	};
};


