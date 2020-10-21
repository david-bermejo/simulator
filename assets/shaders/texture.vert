#version 330 core

layout(location = 0) in vec3 coords;

out vec2 uv;

void main()
{
	gl_Position = vec4(coords, 1.0);
	uv = (coords.xy + vec2(1.0)) / 2.0;
}