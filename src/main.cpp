#include <openglAPI.h>
#include <Mesh.h>
#include <Shader.h>
#include <Level.h>
#include <Broom.h>

Level level; // aie ! mais j'ai besoin de la variable dans le keycallback. à changer éventuellement


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    level.key_callback(window, key, scancode, action, mode);
}

int main(void)
{

	OGL::init();

	for(int i = 0; i < 10; i++) {
		Broom * broom = new Broom(glm::vec3(i - 5, i - 5, -i));
		level.add(broom);
	}

	GLFWwindow* window = glfwGetCurrentContext();
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) {
		level.frame();
	}

	glfwTerminate();

	return 0;
}


