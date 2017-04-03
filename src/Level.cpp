#include "Level.h"

using namespace std;

Level::Level() {
	_startTime = elapsed();
	_camera = Camera(glm::vec3(0.0f, 0.0f, 9.0f));

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearColor(0.1, 0.1, 0.1, 1);
}


void Level::frame() const {
	long int t = elapsed() - _startTime;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT);
    glDepthFunc(GL_LESS);
	
	for(Drawable * const obj: _drawables) {
		obj->update(t);
		obj->draw(t);
	}

	glfwPollEvents();
	glfwSwapBuffers(glfwGetCurrentContext());

}

void Level::add(Drawable * const obj) {
	obj->setCamera(&_camera);
	_drawables.push_back(obj);
}


long int Level::elapsed() const {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	return tp.tv_sec * 1000 + tp.tv_usec / 1000;
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


void Level::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(action == GLFW_PRESS) {			
    	// vvvvvvvvvvvv CODE SALE DE DÉMO À VIRER vvvvvvvvvvvv
		if(key == GLFW_KEY_UP) {
			for(Drawable * const obj: _drawables) { 
				obj->setPosition(obj->getPosition() + glm::vec3(0, 0, 1));
			}
			
		} else {
			for(Drawable * const obj: _drawables) {
				obj->setPosition(obj->getPosition() - glm::vec3(0, 0, 1));
			}
		}


		// ^^^^^^^^^^^^ CODE SALE DE DÉMO À VIRER ^^^^^^^^^^^^
	}
}