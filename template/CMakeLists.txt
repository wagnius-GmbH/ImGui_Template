# CMakeList.txt: CMake-Projekt für "ImGuiTemplate". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (${PROJECT_NAME} "ImGuiTemplate.cpp"  "header.h" "ImGui.hpp" )

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
# ImGui dependecies 
find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)

find_package(implot CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE implot::implot)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)


# Install imgui.ini 
message("************************************")
message("CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
message("************************************\n")
message("************************************")
message("Copy imgui.ini to ${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/config/imgui.ini"  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
message("************************************\n")