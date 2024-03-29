cmake_minimum_required(VERSION 2.8)
project(Magnetar)
set(CMAKE_CXX_STANDARD 11)

# Directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

include(cotire)

# GLFW
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

add_executable(${PROJECT_NAME}

	src/main.cpp

	src/magnetar/application.cpp
	src/magnetar/log.cpp

	src/magnetar/renderer/shader.cpp
	src/magnetar/renderer/texture.cpp

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

target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} glfw)

# PCH
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/magnetar_pch.h")
cotire(${PROJECT_NAME})
