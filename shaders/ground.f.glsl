#version 410

uniform sampler2D textureBalai;
in vec3 Normal;
in vec2 Uv;
out vec4 out_color;



void main()
{
	out_color=vec4(0,.3,0,1);
}
