#version 410

in vec2 position;

void main()
{
	gl_Position = vec4(position.x, position.y, 0.0+0.3,1.0);
}
/*!todo: Create a vertex shader
  * Lab0: simple version
  * Lab1: textured version
  * Lab2: fancier version (shading, cartoon, ...)
  */
