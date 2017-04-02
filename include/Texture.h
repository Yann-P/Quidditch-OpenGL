/**
  *  @author Yann Pellegrini
  *
  */


#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <iostream>
#include <vector>
#include <openglAPI.h>

/** @brief  Stores a texture
  */
class Texture {

public:

	/** @brief  Build a texture object from a path to the tga file
	  * @param A string path to the file
	  */
	explicit Texture(const std::string &);

	/** @brief  Implicit output conversion to a GLuint texture tag
	  */
	operator GLuint();

	/** @brief  Forbid copy
	  */
	Texture(const Texture&) = delete;

private:

	GLuint _tag;

};

#endif