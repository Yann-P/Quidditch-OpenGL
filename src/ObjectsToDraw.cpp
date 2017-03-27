#include "ObjectsToDraw.h"

ObjectsToDraw::ObjectsToDraw()
{
    //ctor
}

ObjectsToDraw::~ObjectsToDraw()
{
    //dtor
}

void ObjectsToDraw::addVAO(std::string nom, const GLuint & vao)
{
    vaoList[nom] = vao;
}


void ObjectsToDraw::addVBO(std::string nom, const GLuint & vbo)
{
    vboList[nom] = vbo;
}


void ObjectsToDraw::addIBO(std::string nom, const GLuint & ibo)
{
    iboList[nom] = ibo;
}


void ObjectsToDraw::addProgram(GLuint vao, const GLuint & program)
{
    programList[vao] = program;
}
