cmake_minimum_required(VERSION 2.8)
project(Magnetar)
set(CMAKE_CXX_STANDARD 11)

# GLFW build flags
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/glfw-3.3)

find_package(OpenGL REQUIRED)

include_directories(
	${OPENGL_INCLUDE_DIR}

	libs
	libs/glad/include
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Magnetar

	src/main.cpp
	src/log.cpp
	src/shader.cpp
	src/texture.cpp

	src/util/profiler.cpp

	libs/glad/src/glad.c
	libs/stb_image/stb_image.cpp

	libs/imgui/imgui_demo.cpp
	libs/imgui/imgui_draw.cpp
	libs/imgui/imgui_impl_glfw.cpp
	libs/imgui/imgui_impl_opengl3.cpp
	libs/imgui/imgui_widgets.cpp
	libs/imgui/imgui.cpp
)

target_link_libraries(Magnetar ${OPENGL_gl_LIBRARY} glfw)
