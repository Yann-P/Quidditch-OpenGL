/**
  *  @author Yann Pellegrini
  *
  */


#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <iostream>
#include <vector>
#include <openglAPI.h>

class Texture {

public:
	Texture(const std::string &);
	operator GLuint();
	Texture(const Texture&) = delete;

private:

	GLuint _tag;

};

#endif