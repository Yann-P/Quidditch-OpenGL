#version 410

uniform sampler2D textureBalai;
in vec3 Normal;
in vec2 Uv;
out vec4 out_color;



void main()
{
	out_color=mix(texture(textureBalai, Uv), vec4(0, 0.5, 0, 1), 0.5); //vec4(Normal, 1); //vec4(1,1,0,1);
}