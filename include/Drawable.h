/**
  *  @author Yann Pellegrini
  *
  */


#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <Shader.h>
#include <Mesh.h>
#include <Texture.h>
#include <Camera.h>
#include <iostream>

/**
  *  @brief Base class for all visual objects.
  *  @abstract
  */
class Drawable
{
	public:
		explicit Drawable(Shader * const, Mesh * const, Texture * const);
		virtual void draw(long int) = 0;
		virtual void update(long int) = 0;
		void setCamera(Camera * const);

		const glm::vec3 & getPosition() const;
		const glm::vec3 & getAngle() const;
		void setPosition(const glm::vec3 &);
		void setAngle(const glm::vec3 &);

	protected:
		Shader * const      _shader;
		Mesh * const        _mesh;
		Texture * const     _texture;
		Camera *            _camera = nullptr;
		GLuint              _ibo;
		GLuint              _vao;
		glm::vec3           _position;
		glm::vec3           _angle;
		

	private:
		/**
		  *  @brief Builds the whole VAO including vertices, indices, UVS and normals.
		  */

		void makeVAO();
};

#endif
