# CMakeList.txt: CMake-Projekt für "ImGuiTemplate". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (ImGuiTemplate "ImGuiTemplate.cpp" "ImGuiTemplate.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ImGuiTemplate PROPERTY CXX_STANDARD 20)
endif()

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
# ImGui dependecies 
#find_package(glad CONFIG REQUIRED)
#target_link_libraries(imGUIexample PRIVATE glad::glad)
