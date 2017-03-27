#include "3DObject.h"

3DObject::3DObject(vao, program);

{
    _vao = vao;
    _program = program;
}


void 3DObject::draw()
{
    glClearColor(0.1, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    //--------- bind shader program [and textures] (see later...)
    glUseProgram(_program);
    //--------- Activate the VAO and call the drawing routine
    glBindVertexArray(_vao);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);


    //--------- Clean state again
    glBindVertexArray(0);
    glUseProgram(0);
}
