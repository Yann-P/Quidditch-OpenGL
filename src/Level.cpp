#include "Level.h"

using namespace std;

Level::Level() {
	_startTime = getTime();
}

void Level::drawLevel() const {

	glClearColor(0.1, 0.1, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
	
	drawAllDrawables();


	GLFWwindow * window = glfwGetCurrentContext();
	glfwPollEvents();
	glfwSwapBuffers(window);

}

void Level::addDrawable(Drawable * const drawable) {
	_drawables.push_back(drawable);
}

void Level::drawAllDrawables() const {

	long int t = getTime() - _startTime;

    for(Drawable * const obj: _drawables) {
        obj->draw(t);
    }
}

// private

long int Level::getTime() const {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

