#ifndef OPENGLAPI_H
#define OPENGLAPI_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <fstream>
#include <iostream>
#include <sys/time.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <iostream>


namespace OGL
{

	void init();
	//void renderFrame(ObjectsToDraw &);
	void file_contents(std::string chemin, int* longueur, GLchar * res);
	void createVBO(float* attributes,int nbVertices,int nbComponents, GLuint & vbo);
	void createIBO(unsigned int* indices,int nbIndices,  GLuint & ibo);
	void createVAO(GLuint & shaderProgram, GLuint & ibo, GLuint & vbo, GLuint & vao);
	GLuint createShaderProgram(GLchar* vSource, const GLint vLength, GLchar* fSource, const GLint fLength);
	char * read_tga(const char *filename, int& width, int& height, int& depth);
	long int time();


}

void initGLFW();
void initGLEW();
short le_short(unsigned char *bytes);

#endif // OPENGLAPI_H
