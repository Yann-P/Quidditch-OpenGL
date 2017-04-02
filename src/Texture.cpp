/**
  *  @author Yann Pellegrini
  *
  */

#include <Texture.h>


Texture::Texture(const std::string & filepath) {
	std::cout << "++Texture(const std::string)" << std::endl;
    int width, height, depth;

    char * data = OGL::read_tga(filepath.c_str(), width, height, depth);

	glGenTextures(1, &_tag);
	glBindTexture(GL_TEXTURE_2D, _tag);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	// ICI FREE LE DATA PNG!!

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}

Texture::operator GLuint() {
	return _tag;
}
