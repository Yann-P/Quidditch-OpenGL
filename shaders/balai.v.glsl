#version 410

in vec3 position;
in vec2 uv;
uniform mat4 proj;
uniform mat4 mv;
out vec2 uv2;
//uniform float t;
void main()
{
	gl_Position = proj * mv * vec4(position, 1.0);
	uv2=vec2(uv.x, 1.0 - uv.y);
}