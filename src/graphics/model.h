#pragma once

#include <string>
#include <gopt.hpp>
#include <GL/glew.h>
#include <vector>

struct Coords
{
	float x, y, z;

	bool operator==(const Coords& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}
};

struct Normal
{
	float x, y, z;

	bool operator==(const Normal& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}
};

struct Vertex
{
	Coords coords;
	Normal normal;

	bool operator==(const Vertex& other) const
	{
		return coords == other.coords && normal == other.normal;
	}
};

namespace std
{
	template <>
	struct hash<Vertex>
	{
		size_t operator()(const Vertex& other) const
		{
			size_t res = 17;

			res = res * 31 + hash<float>()(other.coords.x);
			res = res * 31 + hash<float>()(other.coords.y);
			res = res * 31 + hash<float>()(other.coords.z);

			res = res * 31 + hash<float>()(other.normal.x);
			res = res * 31 + hash<float>()(other.normal.y);
			res = res * 31 + hash<float>()(other.normal.z);

			return res;
		}
	};
}

class Model
{
public:
	gopt::Vec3 position;
	gopt::Vec3 rotation;

	gopt::Mat4f rotation_matrix;
	gopt::Vec3f color;

	GLuint vao;
	std::vector<GLuint> vbos;
	unsigned int elements;

public:
	Model() = default;
	Model(const std::string& path);
	~Model();

	gopt::Mat4f transform();

private:
	void load(const std::vector<unsigned int>& data);
};