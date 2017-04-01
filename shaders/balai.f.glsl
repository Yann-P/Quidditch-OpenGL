#version 410

in vec3 normal2;
out vec4 out_color;

void main()
{
	out_color=vec4((normal2+1)/2.0,1); //vec4(1,1,0,1);
}