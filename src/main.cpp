#include <openglAPI.h>
#include <Mesh.h>
#include <Shader.h>
#include <Level.h>
#include <Broom.h>
#include <character.h>
#include <GoldenSnitch.h>
#include <obstacle.h>
#include <fleche.h>

Level level;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	level.key_callback(window, key, scancode, action, mode);
}

int main(void)
{

	OGL::init();
	GLFWwindow* window 		= glfwGetCurrentContext();


	Broom * broom 			= new Broom(glm::vec3(2, 2, -50));
	GoldenSnitch * snitch 	= new GoldenSnitch(glm::vec3(-3, -3, -10));
	Character * character 	= new Character(glm::vec3(-2, 5, -10));
	Arrow * arrow 			= new Arrow(glm::vec3(0, 5, -30));

	Obstacle * obstacles[3];

	for(int i = 0; i < 3; i++) {
		obstacles[i] = new Obstacle(glm::vec3(i - 3, i - 3, -i*10));
		obstacles[i]->setCharacter(character);
		level.add(obstacles[i]);
	}

	arrow->setCharacter(character);
	arrow->setGoldenSnitch(snitch);



	glfwSetKeyCallback(window, key_callback);

	level.add(arrow);
	level.add(broom);
	level.add(snitch);
	level.add(character);

	while (!glfwWindowShouldClose(window)) {
		level.frame();
	}

	delete broom;
	delete snitch;
	delete character;
	delete arrow;

	for(int i = 0; i < 3; i++) delete obstacles[i];

	glfwTerminate();

	return 0;
}


