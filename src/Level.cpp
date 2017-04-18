#include "Level.h"

using namespace std;

Level::Level(const std::string & map) {
	_startTime = OGL::time();
	_camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f));
	_input = Input();

	loadMap(map);

	

	glClearColor(0.1, 0.1, 0.1, 1);
}


void Level::loadMap(const std::string & map) {

	std::ifstream file;
	file.open(map); // open a file
	if (!file.good()) {
		std::cerr << "impossible de charger la map au chemin " << map << std::endl;
		throw "erreur parsemap";
	}

	string width_s;
	string height_s;
	string data_s;

	std::getline(file, width_s, ' ');
	std::getline(file, height_s, '\n');
	_width = std::stoi(width_s);
	_height = std::stoi(height_s);


	for (int l = 0; l < _height; l++) {

		std::vector<int> * line = new std::vector<int>;
		
		for(int c = 0; c < _width; c++) {
		
			if(c == _width - 1)
				std::getline(file, data_s, '\n');
			else
				std::getline(file, data_s, '\t');

			line->push_back(std::stoi(data_s));

		}

		_obstaclesData.push_back(line);

	}
}

void Level::load(Character * c) {
	for(int y = 0; y < _height; y++) {
		
		for(int x = 0; x < _width; x++) {

			if(_obstaclesData[y]->at(x) == 0)
				continue;
			Obstacle * obstacle = new Obstacle(x * 10, y * 10, _obstaclesData[y]->at(x));
			obstacle->setCharacter(c);
		 	add(obstacle);
		 }
	}
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


void Level::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if(action == GLFW_PRESS)
        _input.setKey(key, true);
    else if(action == GLFW_RELEASE)
        _input.setKey(key, false);
}
