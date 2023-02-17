cmake_minimum_required(VERSION 3.24)
include(FetchContent)
set(CMAKE_CXX_STANDARD 17)

##########################################################
# Global project setup
##########################################################
message("Setting up project...")
project(elements)
include_directories(include)

##########################################################
# ImGui version
##########################################################
# Download imgui_bundle
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
        imgui_bundle
        GIT_REPOSITORY https://github.com/pthom/imgui_bundle.git
        GIT_PROGRESS TRUE
        # Enter the desired git tag below
        GIT_TAG main
)
FetchContent_MakeAvailable(imgui_bundle)
# Make cmake function `imgui_bundle_add_app` available
list(APPEND CMAKE_MODULE_PATH ${IMGUIBUNDLE_CMAKE_PATH})
include(imgui_bundle_add_app)

# Download imgui memory editor.
FetchContent_Declare(
        imgui_memedit
        GIT_REPOSITORY https://github.com/ocornut/imgui_club.git
        GIT_PROGRESS TRUE
        GIT_TAG main
)
FetchContent_MakeAvailable(imgui_memedit)
include_directories(${imgui_memedit_SOURCE_DIR}/imgui_memory_editor)

# Including sources.
file(GLOB_RECURSE imguiSources src/imgui/** src/*)
message("Included source files: ${imguiSources}")

# Add ImGui version targets
# Library
# Maybe I should provide example project with example CMakeLists.txt that will
# compile the project with selected GUI lib instead of compiling the project to the
# standalone lib manually.
# to-do (maybe not)
#add_library(elements_imgui_lib include/elements/element.h src/imgui/imgui_number.cpp include/elements/number.h include/elements/package.h src/imgui/imgui_package.cpp include/elements/app.h src/imgui/imgui_app.cpp)
#target_link_libraries(elements_imgui_lib imgui)

# Demo application
imgui_bundle_add_app(elements_imgui_demo main.cpp ${imguiSources})

##########################################################
# Text-only version
##########################################################
# to-do

##########################################################
# Qt version
##########################################################
# to-do