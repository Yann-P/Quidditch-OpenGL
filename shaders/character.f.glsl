#version 410

uniform sampler2D textureBalai;
in vec3 Normal;
in vec2 Uv;
out vec4 out_color;



void main()
{
	out_color=vec4(Normal * vec3(1, 0.5, 0), 1); //vec4(1,1,0,1);
}