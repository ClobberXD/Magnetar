#include "shader.h"

#include <iostream>
#include <fstream>

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath)
{
	// Parse shader files
	std::string vertexSrc   = parseShaderSource(vertexPath);
	std::string fragmentSrc = parseShaderSource(fragmentPath);

	// Compile and link shaders
	linkShaderProgram(compileShader(GL_VERTEX_SHADER, vertexSrc),
			compileShader(GL_FRAGMENT_SHADER, fragmentSrc));
}

const std::string Shader::parseShaderSource(const std::string &path)
{
	std::string src;
	std::ifstream in;
	in.open(path, std::ios::binary);
	getline(in, src, '\0');

	return src;
}

const unsigned int Shader::compileShader(const unsigned int type, const std::string &shaderSrc)
{
	unsigned int id = glCreateShader(type);
	const char *src = shaderSrc.c_str();
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);

	// Error-checking
	int success;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		std::string type_str = (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT");
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" + type_str + "::COMPILATION_FAILED\n" <<
				infoLog << std::endl;
	}

	return id;
}

void Shader::linkShaderProgram(unsigned int v_ID, unsigned int f_ID)
{
	m_ID = glCreateProgram();
	glAttachShader(m_ID, v_ID);
	glAttachShader(m_ID, f_ID);
	glLinkProgram(m_ID);

	// Error-checking
	int success;
	char infoLog[512];
	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(v_ID);
	glDeleteShader(f_ID);
}

const int Shader::getUniformLocation(const std::string &name)
{
	int location;

	// Check if uniform's location is present in cache
	if (m_uniform_cache.find(name) != m_uniform_cache.end()) {
		location = m_uniform_cache[name];
	} else {
		location = glGetUniformLocation(m_ID, name.c_str());
		m_uniform_cache[name] = location;
	}

	// TODO: Throw an exception (or log the error?) if location == -1

	return location;
}

void Shader::use()
{
	glUseProgram(m_ID);
}

/******************************/

void Shader::upload(const std::string &name, bool value)
{
	glUseProgram(m_ID);

	glUniform1i(getUniformLocation(name), (int)value);
}

void Shader::upload(const std::string &name, int value)
{
	glUseProgram(m_ID);

	glUniform1i(getUniformLocation(name), value);
}

void Shader::upload(const std::string &name, float value)
{
	glUseProgram(m_ID);

	glUniform1f(getUniformLocation(name), value);
}

void Shader::upload(const std::string &name, const glm::vec3 &value)
{
	glUseProgram(m_ID);

	glUniform3fv(getUniformLocation(name), 3, value_ptr(value));
}

void Shader::upload(const std::string &name, const glm::vec4 &value)
{
	glUseProgram(m_ID);

	glUniform4fv(getUniformLocation(name), 4, value_ptr(value));
}

void Shader::upload(const std::string &name, const glm::mat4 &value)
{
	glUseProgram(m_ID);

	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, value_ptr(value));
}
