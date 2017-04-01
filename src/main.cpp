#include <openglAPI.h>
#include <Mesh.h>
#include <Shader.h>
#include <Level.h>
#include <Broom.h>

#include <../include/fleche.h>
#include <../include/pave.h>



int main(void)
{

 	OGL::init();

 	Level level;
 	Broom broom;

 	level.addDrawable(&broom);

 	Mesh balai("../blend/balai.blend");
 	Shader shader("../shaders/balai.v.glsl", "../shaders/balai.f.glsl");



	GLFWwindow* window = glfwGetCurrentContext();

 	while (!glfwWindowShouldClose(window)) {
 		level.drawLevel();
 		//render(shader, vao, balai.getIndices().size(), start);
	}

	glfwTerminate();



  	return 0;
}

// vim: ft=cpp foldmethod=marker:
