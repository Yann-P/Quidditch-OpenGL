#ifndef 3DOBJECT_H
#define 3DOBJECT_H

#include <>


class 3DObject
{
    public:
        3DObject(GLuint vao, GLuint program);
        virtual void draw() = 0;
    protected:
    private:
        GLuint _vao;
        GLuint _program;
};

#endif // 3DOBJECT_H
