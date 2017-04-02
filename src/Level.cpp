#include "Level.h"

using namespace std;

Level::Level() {
	_startTime = elapsed();

	glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(0.1, 0.1, 0.1, 1);
}


void Level::frame() const {
	long int t = elapsed() - _startTime;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for(Drawable * const obj: _drawables) {
		obj->update(t);
        obj->draw(t);
    }

	GLFWwindow * window = glfwGetCurrentContext();
	glfwPollEvents();
	glfwSwapBuffers(window);

}

void Level::add(Drawable * const obj) {
	_drawables.push_back(obj);
}


long int Level::elapsed() const {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

