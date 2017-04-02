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
 	Broom broom(glm::vec3(0, 0, -5));

 	level.add(&broom);


	GLFWwindow* window = glfwGetCurrentContext();

 	while (!glfwWindowShouldClose(window)) {
 		level.frame();
	}

	glfwTerminate();

  	return 0;
}
