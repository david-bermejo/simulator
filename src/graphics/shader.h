#pragma once

#include <GL/glew.h>
#include <vector.hpp>
#include <matrix.hpp>
#include <string>

class Shader
{
private:
	GLuint shader_id;

private:
	void init(const std::string& vertex_path, const std::string& fragment_path);
	GLuint compile(const std::string& path, GLenum type);

public:
	Shader();
	Shader(const std::string& vertex_path, const std::string& fragment_path);
	~Shader();

	void begin();
	void end();

	void set(const std::string& var, bool value);
	void set(const std::string& var, int value);
	void set(const std::string& var, unsigned int value);
	void set(const std::string& var, float value);
	void set(const std::string& var, const gopt::Vector_t<float, 2>& value);
	void set(const std::string& var, const gopt::Vector_t<float, 3>& value);
	void set(const std::string& var, const gopt::Matrix_t<float, 3, 3>& value);
	void set(const std::string& var, const gopt::Matrix_t<float, 4, 4>& value);
};