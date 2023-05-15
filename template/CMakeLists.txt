# CMakeList.txt: CMake-Projekt für "ImGuiTemplate". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.



# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (template "ImGuiTemplate.cpp"  "header.h" "ImGui.cpp")

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
# ImGui dependecies 
find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)

 # this is heuristically generated, and may not be correct
find_package(implot CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE implot::implot)