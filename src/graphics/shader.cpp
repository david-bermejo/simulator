#include "shader.h"

#include "../utils/file_utils.h"
#include <iostream>

constexpr auto default_vertex = "assets/shaders/default.vert";
constexpr auto default_fragment = "assets/shaders/default.frag";

Shader::Shader()
{
	init(default_vertex, default_fragment);
}

Shader::Shader(const std::string& vertex_path, const std::string& fragment_path)
{
	init(vertex_path, fragment_path);
}

Shader::~Shader()
{
	glUseProgram(0);
	glDeleteProgram(shader_id);
}

void Shader::init(const std::string& vertex_path, const std::string& fragment_path)
{
	GLuint vertex_id = compile(vertex_path, GL_VERTEX_SHADER);
	GLuint fragment_id = compile(fragment_path, GL_FRAGMENT_SHADER);

	shader_id = glCreateProgram();
	glAttachShader(shader_id, vertex_id);
	glAttachShader(shader_id, fragment_id);
	glLinkProgram(shader_id);

	int success;
	glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		int log_length;
		glGetProgramiv(shader_id, GL_INFO_LOG_LENGTH, &log_length);

		char* info_log = new char[log_length];
		glGetProgramInfoLog(shader_id, log_length, nullptr, info_log);
		std::cerr << "Shader: Linking failed!\n";
		std::cerr << "LOG: " << info_log << std::endl;
		delete[] info_log;
		return;
	}

	glDeleteShader(vertex_id);
	glDeleteShader(fragment_id);
}

GLuint Shader::compile(const std::string& path, GLenum type)
{
	GLuint id = glCreateShader(type);
	std::vector<unsigned char> file = readFile(path);
	const std::string str = std::string(file.begin(), file.end());
	const char* code = str.c_str();

	int success;
	glShaderSource(id, 1, &code, nullptr);
	glCompileShader(id);

	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		std::cerr << "Shader: Could not compile " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment") << " shader! Path: " << path << "\n";
		int log_length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &log_length);

		char* infoLog = new char[log_length];
		glGetShaderInfoLog(id, log_length, nullptr, infoLog);
		std::cerr << "LOG: " << infoLog << std::endl;
		delete[] infoLog;
		return 0;
	}

	return id;
}

void Shader::begin()
{
	glUseProgram(shader_id);
}

void Shader::end()
{
	glUseProgram(0);
}

void Shader::set(const std::string& var, bool value)
{
	glUniform1i(glGetUniformLocation(shader_id, var.c_str()), (int)value);
}

void Shader::set(const std::string& var, int value)
{
	glUniform1i(glGetUniformLocation(shader_id, var.c_str()), value);
}

void Shader::set(const std::string& var, unsigned int value)
{
	glUniform1ui(glGetUniformLocation(shader_id, var.c_str()), value);
}

void Shader::set(const std::string& var, float value)
{
	glUniform1f(glGetUniformLocation(shader_id, var.c_str()), value);
}

void Shader::set(const std::string& var, const gopt::Vector_t<float, 2>& value)
{
	glUniform2fv(glGetUniformLocation(shader_id, var.c_str()), 1, value.begin());
}

void Shader::set(const std::string& var, const gopt::Vector_t<float, 3>& value)
{
	glUniform3fv(glGetUniformLocation(shader_id, var.c_str()), 1, value.begin());
}

void Shader::set(const std::string& var, const gopt::Matrix_t<float, 3, 3>& value)
{
	glUniformMatrix3fv(glGetUniformLocation(shader_id, var.c_str()), 1, true, &value[0][0]);
}

void Shader::set(const std::string& var, const gopt::Matrix_t<float, 4, 4>& value)
{
	glUniformMatrix4fv(glGetUniformLocation(shader_id, var.c_str()), 1, true, &value[0][0]);
}