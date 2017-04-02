#version 410

in vec3 position;
uniform mat4 proj;
uniform mat4 mv;
//uniform float t;
void main()
{
	gl_Position = proj * mv * vec4(position, 1.0);
}