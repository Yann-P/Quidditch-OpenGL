#include <openglAPI.h>
#include <Mesh.h>
#include <Shader.h>
#include <Level.h>
#include <Broom.h>
#include <GoldenSnitch.h>

Level level; // aie ! mais j'ai besoin de la variable dans le keycallback. à changer éventuellement


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    level.key_callback(window, key, scancode, action, mode);
}

int main(void)
{

	OGL::init();

	Broom * brooms[6];

	for(int i = 0; i < 6; i++) {
		brooms[i] = new Broom(glm::vec3(i - 3, i - 3, -i*10));
		level.add(brooms[i]);
	}


	GoldenSnitch *snitch = new GoldenSnitch(glm::vec3(-3,-3,0));
	level.add(snitch);


	GLFWwindow* window = glfwGetCurrentContext();
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) {
		level.frame();
	}


	delete[] brooms;
	delete snitch;

	glfwTerminate();

	return 0;
}


