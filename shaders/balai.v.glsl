#version 410

in vec3 position;
in vec3 normal;
in vec2 uv;
uniform mat4 proj;
uniform mat4 mv;
out vec2 Uv;
out vec3 Normal;

void main()
{
	gl_Position = proj * mv * vec4(position, 1.0);
	Uv=uv;
	Normal=normal;
}