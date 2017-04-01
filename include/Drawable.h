#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <Shader.h>
#include <Mesh.h>

class Drawable
{
    public:
        Drawable(Shader, Mesh);
        virtual void draw(long int) = 0;
    protected:
        Shader & _shader;
        Mesh & _mesh;
        GLuint _ibo;
        GLuint _vbo;
        GLuint _vao;
        int _nbIndices;
    private:
};

#endif
