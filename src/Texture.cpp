#include <Texture.h>

Texture::Texture(const std::string & filepath) {
    int width, height, depth;

    char * data = OGL::read_tga(filepath.c_str(), width, height, depth);

	glGenTextures(1, &_tag);
	glBindTexture(GL_TEXTURE_2D, _tag); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // glTexImage2D(GL_TEXTURE_2D, 0, hasAlpha ? 4 : 3, width,
    //              height, 0, hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE,
    //              textureImage);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glGenerateMipmap(GL_TEXTURE_2D);

	// ICI FREE LE DATA PNG!!

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}

Texture::operator GLuint() {
	return _tag;
}
