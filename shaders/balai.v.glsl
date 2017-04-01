#version 410

in vec3 position;
in vec3 normal;
uniform mat4 proj;
uniform mat4 mv;
out vec3 normal2;
//uniform float t;
void main()
{
	gl_Position = proj * mv * vec4(position, 1.0);
	normal2 = normal;
}