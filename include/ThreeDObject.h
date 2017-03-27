#ifndef THREEDOBJECT_H
#define THREEDOBJECT_H

#include <openglAPI.h>

class ThreeDObject
{
    public:
        ThreeDObject(GLuint vao, GLuint program);
        virtual void draw() = 0;
    protected:
    private:
        GLuint _vao;
        GLuint _program;
};

#endif // 3DOBJECT_H
