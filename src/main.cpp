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


	GLFWwindow* window = glfwGetCurrentContext();

 	while (!glfwWindowShouldClose(window)) {
 		level.drawLevel();
	}

	glfwTerminate();

  	return 0;
}
