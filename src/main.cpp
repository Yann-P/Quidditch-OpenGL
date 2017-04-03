#include <openglAPI.h>
#include <Mesh.h>
#include <Shader.h>
#include <Level.h>
#include <Broom.h>
#include <character.h>

Level level; // aie ! mais j'ai besoin de la variable dans le keycallback. à changer éventuellement


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    level.key_callback(window, key, scancode, action, mode);
}

int main(void)
{

	OGL::init();

	Broom * brooms[6];

    //Character * seeker[6];

	for(int i = 0; i < 6; i++) {
		brooms[i] = new Broom(glm::vec3(i - 3, i - 3, -i*10));
		level.add(brooms[i]);

        //test character
        //seeker[i] = new Character(glm::vec3(i - 3, i - 3, -i*10));
        //level.add(seeker[i]);
	}

    /*test character + move*/
    Character * seeker = new Character(glm::vec3(0,0,0)) ;
    level.add(seeker);
    


	GLFWwindow* window = glfwGetCurrentContext();
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) {
		level.frame();
	}


	delete[] brooms;
    delete seeker;

	glfwTerminate();

	return 0;
}


