#include "ObjectsToDraw.h"

using namespace std;

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

void ObjectsToDraw::drawAll()
{

    //--------- clear the color-buffer and the depth-buffer, set some states
    glClearColor(0.1, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    for (pair<string, GLuint> p: vaoList)
    {
    //--------- bind shader program [and textures] (see later...)
        glUseProgram(programList[p.second]);
    //--------- Activate the VAO and call the drawing routine
        glBindVertexArray(p.second);

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    }
    GLFWwindow* window = glfwGetCurrentContext();
//
    glfwPollEvents();
    glfwSwapBuffers(window);

    //--------- Clean state again
    glBindVertexArray(0);
    glUseProgram(0);
}
