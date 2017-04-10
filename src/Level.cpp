#include "Level.h"

using namespace std;

Level::Level() {
	_startTime = OGL::time();
	_camera = Camera(glm::vec3(0.0f, 0.0f, 9.0f));
	_input = Input();

	glClearColor(0.1, 0.1, 0.1, 1);
}


void Level::frame() {
	long int t = OGL::time() - _startTime;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_NORMALIZE);

	for(Drawable * const obj: _drawables) {
		obj->update(t);
		obj->draw(t);
	}

	if(_input.isDown(GLFW_KEY_KP_ADD)) {
		_camera.setZoom(_camera.getZoom() + .1);
	} else if(_input.isDown(GLFW_KEY_KP_SUBTRACT)) {
		_camera.setZoom(_camera.getZoom() - .1);
	}

	glfwPollEvents();
	glfwSwapBuffers(glfwGetCurrentContext());

}

void Level::add(Drawable * const obj) {
	obj->setCamera(&_camera);
	obj->setInput(&_input);
	_drawables.push_back(obj);
}


// À DÉBUGGER!

// bool Level::collisionWithObstacle() const {

//   vector<Obstacle>::iterator itBegin= _obstacles.begin();
//   vector<Obstacle>::iterator itEnd= _obstacles.end();

//   while(itBegin!=itEnd){
//     if(!((*itBegin).detectCollision(_seeker->getPosition()) ) )
//       {
// 	return true;
//       }
//     ++itBegin;
//   }
// }


void Level::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if(action == GLFW_PRESS)
        _input.setKey(key, true);
    else if(action == GLFW_RELEASE)
        _input.setKey(key, false);
}
