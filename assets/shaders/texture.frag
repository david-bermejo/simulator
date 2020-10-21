#version 330 core

in vec2 uv;

out vec4 color;

uniform sampler2D render_texture;

void main()
{
	color = texture(render_texture, uv);
}