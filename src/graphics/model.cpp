#include "model.h"

#include <stl_reader.h>
#include <unordered_map>
#include <iostream>

Model::Model(const std::string& path)
	: rotation_matrix(gopt::eye<float, 4>()), color(1.0f, 1.0f, 1.0f)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<float> file_coords;
	std::vector<float> file_normals;
	std::vector<unsigned int> tris;
	std::vector<unsigned int> solids;

	stl_reader::ReadStlFile(path.c_str(), file_coords, file_normals, tris, solids);

	std::vector<Coords> coords;
	coords.resize(file_coords.size() / 3);
	for (int i = 0; i < coords.size(); i++)
		coords[i] = {file_coords[3*i], file_coords[3*i+1], file_coords[3*i+2]};

	std::vector<Normal> normals;
	normals.resize(file_normals.size() / 3);
	for (int i = 0; i < normals.size(); i++)
		normals[i] = {file_normals[3*i], file_normals[3*i+1], file_normals[3*i+2]};

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	std::unordered_map<Vertex, unsigned int> map(0);
	for (int i = 0; i < tris.size(); i++)
	{
		Vertex vertex { coords[tris[i]], normals[i/3] };

		if (auto it = map.find(vertex); it != map.end()) {
			indices.push_back(it->second);
		} else {
			auto pair = std::make_pair(vertex, map.size());
			map.insert(pair);
			vertices.push_back(vertex);
			indices.push_back(pair.second);
		}
	}

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Vertex::coords));
	glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Vertex::normal));
	vbos.push_back(vbo);

	load(indices);

	glBindVertexArray(0);
}

Model::~Model()
{
	glDeleteBuffers(vbos.size(), vbos.data());
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vao);
}

gopt::Mat4f Model::transform()
{
	const auto t = gopt::translation<float>((float)position[1], (float)position[2], (float)position[0]);
	const auto r = gopt::rotation<float>((float)rotation[2], (float)rotation[0], (float)rotation[1]);
	const auto s = gopt::scaling(gopt::Vec3f(0.01f));

	return t * r * rotation_matrix * s;
}

void Model::load(const std::vector<unsigned int>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), data.data(), GL_STATIC_DRAW);
	vbos.push_back(vbo);

	elements = data.size();
}