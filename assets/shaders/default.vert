#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 projection = mat4(1.0);
uniform mat4 transform = mat4(1.0);

out vec3 frag_normal;
out vec3 frag_position;

void main()
{
	gl_Position = projection * transform * vec4(position, 1.0);
	frag_normal = mat3(transpose(inverse(transform))) * normal;
	frag_position = vec3(transform * vec4(position, 1.0));
}