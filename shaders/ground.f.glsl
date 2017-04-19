#version 410

uniform sampler2D textureSol;
in vec3 Normal;
in vec2 Uv;
out vec4 out_color;



void main()
{
	out_color=texture(textureSol, Uv * 500);
}