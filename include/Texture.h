#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <iostream>
#include <openglAPI.h>

class Texture {

public:
	Texture(std::string &);
	operator GLuint();

private:

	GLuint _tag;

};

#endif