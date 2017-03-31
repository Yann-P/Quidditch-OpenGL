#include <openglAPI.h>
#include <Mesh.h>
#include <ObjectsToDraw.h>

#include <../include/fleche.h>
#include <../include/pave.h>


int main(void)
 {

/*
    Fleche test();
    int vec[3];
    vec[0]=1;
    vec[1]=2;
    vec[2]=3;
    Pave test2(vec,3,4,5);
*/





 	OGL::init();

    float positions[] = {0.2f,0.2f,0.2f,1.0f,1.0f,1.0f};
    float pos2[] = {0.0f , 0.0f, 1.0f, -1.0f, 0.0f,-1.0f};
 	unsigned int indices[] = {0, 1, 2};
 	//unsigned int ind2[] = {0, 1, 2};

    float positionsPave[] = {0.2f,0.2f,0.2f,1.0f,1.0f,1.0f, 0.0f, 0.0f};
    unsigned int indicesPave[] = {};


    Mesh test(positionsPave, indicesPave);
    //Mesh test2( positionsPave, indicesPave);

    //Mesh test(positions, indices);
    Mesh test2( pos2, indices);








    GLuint vbo;
    GLuint vbo2;
    GLuint ibo;
    GLuint vao2;
    GLuint vao;
    GLint vLength, fLength;
 	GLchar * vSource = new GLchar[10000];
 	GLchar * fSource = new GLchar[10000];
 	GLuint program;

 	ObjectsToDraw reg;

 	OGL::createVBO(test.getPositions(), 3,2,vbo);
 	OGL::createVBO(test2.getPositions(), 3,2,vbo2);
 	OGL::createIBO(test.getIndices(),3, ibo);
 	OGL::createIBO(test2.getIndices(),3, ibo);

    reg.addVBO("vboTest", vbo);
    reg.addVBO("vboTest2", vbo2);
    reg.addIBO("iboTest", ibo);
    reg.addIBO("iboTest2", ibo);

 	OGL::file_contents("../shaders/myOwnGLSLProg.v.glsl", &vLength, vSource);
 	OGL::file_contents("../shaders/myOwnGLSLProg.f.glsl", &fLength, fSource);

    program = OGL::createShaderProgram(vSource, vLength, fSource, fLength);

    OGL::createVAO(program,ibo, vbo, vao);
    OGL::createVAO(program,ibo, vbo2, vao2);

    reg.addVAO("test1", vao);
    reg.addVAO("test2", vao2);
    reg.addProgram(vao, program);
    reg.addProgram(vao2, program);

    GLFWwindow* window = glfwGetCurrentContext();

 	while (!glfwWindowShouldClose (window))
 	{
        //OGL::renderFrame(program, vao);
 		OGL::renderFrame(reg);


	}

	glfwTerminate();

	delete[] vSource;
	delete[] fSource;

 	return 0;
}

// vim: ft=cpp foldmethod=marker:
