#version 410

in vec3 position;
in vec3 normal;
in vec2 uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 Uv;
out vec3 Normal;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0);
	Uv=vec2(uv.x, 1 - uv.y);
	Normal=normal;
}