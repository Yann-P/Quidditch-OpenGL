#include <openglAPI.h>
#include <Mesh.h>

int main(void)
 {
 	OGL::init();

 	float positions[] = {0.2f,0.2f,0.2f,1.0f,1.0f,1.0f};
 	unsigned int indices[] = {0, 1, 2};

 	Mesh test(positions, indices);

    GLuint vbo;
    GLuint ibo;
    GLuint vao;
    GLint vLength, fLength;
 	GLchar * vSource = new GLchar[10000];
 	GLchar * fSource = new GLchar[10000];
 	GLuint program;

 	OGL::createVBO(test.getPositions(), 3,2,vbo);
 	OGL::createIBO(test.getIndices(),3, ibo);

 	OGL::file_contents("../shaders/myOwnGLSLProg.v.glsl", &vLength, vSource);
 	OGL::file_contents("../shaders/myOwnGLSLProg.f.glsl", &fLength, fSource);

    program = OGL::createShaderProgram(vSource, vLength, fSource, fLength);

    OGL::createVAO(program,ibo, vbo, vao);

    GLFWwindow* window = glfwGetCurrentContext();

 	while (!glfwWindowShouldClose (window))
 	{
 		OGL::renderFrame(program, vao);
	}

	glfwTerminate();

	delete[] vSource;
	delete[] fSource;

 	return 0;
}

// vim: ft=cpp foldmethod=marker:
