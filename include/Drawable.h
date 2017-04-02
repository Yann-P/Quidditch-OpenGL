/**
  *  @author Yann Pellegrini
  *
  */


#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <Shader.h>
#include <Mesh.h>
#include <Texture.h>
#include <iostream>

class Drawable
{
    public:
        Drawable(Shader * const, Mesh * const, Texture * const);
        virtual void draw(long int) = 0;
    protected:
        Shader * const _shader;
        Mesh * const _mesh;
        Texture * const _texture;
        GLuint _ibo;
        GLuint _vao;
    private:
};

#endif
