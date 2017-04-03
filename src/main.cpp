#include <openglAPI.h>
#include <Mesh.h>
#include <Shader.h>
#include <Level.h>
#include <Broom.h>
#include <obstacle.h>

Level level; // aie ! mais j'ai besoin de la variable dans le keycallback. à changer éventuellement


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    level.key_callback(window, key, scancode, action, mode);
}

int main(void)
{

	OGL::init();

    Obstacle * obstacle[3];
    Broom * broom = new Broom(glm::vec3(2, 2, -50));
    level.add(broom);

    for(int i = 0; i < 3; i++) {
        obstacle[i] = new Obstacle(glm::vec3(i - 3, i - 3, -i*10));
        obstacle[i]->setCharacter(broom);
        level.add(obstacle[i]);
	}




	GLFWwindow* window = glfwGetCurrentContext();
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) {
		level.frame();
	}



	glfwTerminate();

	return 0;
}


