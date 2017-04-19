#include <openglAPI.h>
#include <Mesh.h>
#include <Shader.h>
#include <Level.h>
#include <Dome.h>
#include <character.h>
#include <GoldenSnitch.h>
#include <obstacle.h>
#include <fleche.h>
#include <Ground.h>

Level level("../maps/1.txt");

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	level.key_callback(window, key, scancode, action, mode);
}

int main(void)
{

	OGL::init();
	long int lastFrame = OGL::time();
	long int t;

	GLFWwindow * window 	= glfwGetCurrentContext();
	Ground * ground 		= new Ground;
	//Broom * broom 			= new Broom(glm::vec3(2, 50, -50));
	Dome * dome 			= new Dome(glm::vec3(0, 0, 0));
	GoldenSnitch * snitch 	= new GoldenSnitch(glm::vec3(-3, 50, -10));
    Character * character 	= new Character(glm::vec3(-20, 60, -10));
	Arrow * arrow 			= new Arrow(glm::vec3(0, 50, -30));

	// Obstacle * obstacles[3];

	// for(int i = 0; i < 3; i++) {
	// 	obstacles[i] = new Obstacle(i - 3, -i*10, 20);
	// 	obstacles[i]->setCharacter(character);
	// 	level.add(obstacles[i]);
	// }

	arrow->setCharacter(character);
	arrow->setGoldenSnitch(snitch);

	snitch->setCharacter(character);



	glfwSetKeyCallback(window, key_callback);

	level.add(ground);
	level.add(arrow);
	level.add(dome);
	level.add(snitch);
	level.add(character);
	level.load(character);

	while (!glfwWindowShouldClose(window)) {
		t = OGL::time();
		if(t - lastFrame > (1/60.f) * 1000) {
			level.frame();
			lastFrame = t;
		}
		
	}

	delete ground;
	delete dome;
	delete snitch;
	delete character;
	delete arrow;


	glfwTerminate();

	return 0;
}


