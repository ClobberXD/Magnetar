#pragma once

#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

class Shader
{
public:
	Shader(const std::string &vertexPath, const std::string &fragmentPath);

	const unsigned int getID() const { return m_ID; }

	void use();

	// Overloaded uniform setter
	void upload(const std::string &name, bool value);
	void upload(const std::string &name, float value);
	void upload(const std::string &name, int value);
	void upload(const std::string &name, const glm::vec3 &value);
	void upload(const std::string &name, const glm::vec4 &value);
	void upload(const std::string &name, const glm::mat4 &value);

private:
	const std::string parseShaderSource(const std::string &path);
	const unsigned int compileShader(const unsigned int type, const std::string &shader_src);
	void linkShaderProgram(const unsigned int v_ID, const unsigned int f_ID);
	const int getUniformLocation(const std::string &name);

	std::unordered_map<std::string, int> m_uniform_cache;

	unsigned int m_ID;
};
