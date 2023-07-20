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

	// GL 3.3 + GLSL 150
	const char* glsl_version = "#version 150";

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
	}
};





GLFWwindow* initImgui(int win_w = 1280, int win_h = 720, std::string win_title = "LSystem") {

    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        cout << "errpr om glgwInit()";

    // Decide GL+GLSL versions
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Dear ImGui - Example", NULL, NULL);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  // tie window context to glad's opengl funcs
		throw("Unable to context to OpenGL");

	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

	return window;

}

void termImgui(GLFWwindow* window) {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

}
