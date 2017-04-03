#include <openglAPI.h>
#include <Mesh.h>
#include <Shader.h>
#include <Level.h>
#include <Broom.h>
#include <character.h>
#include <GoldenSnitch.h>

Level level; // aie ! mais j'ai besoin de la variable dans le keycallback. à changer éventuellement


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    level.key_callback(window, key, scancode, action, mode);
}

int main(void)
{

	OGL::init();

	Broom * broom = new Broom(glm::vec3(0, 0, -10));
	GoldenSnitch * snitch = new GoldenSnitch(glm::vec3(-3, -3, -10));
	Character * character = new Character(glm::vec3(-2, -2, -10));

	level.add(broom);
	level.add(snitch);
	level.add(character);


	GLFWwindow* window = glfwGetCurrentContext();
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) {
		level.frame();
	}


	glfwTerminate();

	return 0;
}


