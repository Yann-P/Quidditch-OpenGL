#version 410

uniform sampler2D textureBalai;
in vec2 uv2;
out vec4 out_color;



void main()
{
	out_color=texture(textureBalai, uv2); //vec4(1,1,0,1);
}