/**
 * \file GoldenSnitch.cpp
 * \author Julien Lepasquier
 * \date 20/03/2017
 *
 */

#include "GoldenSnitch.h"


#define MAIN_SPEED		0.05
#define PARASITE_SPEED	0.5


 GoldenSnitch::GoldenSnitch(glm::vec3 position) : Drawable(
 	new Shader("../shaders/snitch.v.glsl", "../shaders/snitch.f.glsl"),
 	new Mesh("../blend/cube.blend"),
 	new Texture("../texture/texture_peut_etre.tga")
 	) {
 	_position = position;

 }



 void GoldenSnitch::setCharacter(const Character * character) {
 	_character = character;
 }



 void GoldenSnitch::update(long int t) {

	// Random Trajectory if char isn't moving
 	if ( _character->getSpeed() == 0 ) {
 		if ( _path.empty() ) {
 			createRandomPath();
 		}
 	} 
 	else	//Run away from char if char is moving
 	{
 		flee(); 
 	}

	int direction = _path.top().first;
	float speed = _path.top().second;
	_path.pop();

	updatePosition(direction, speed);
 }



/*
void GoldenSnitch::update(long int t) {

	if ( _path.empty() ) {
		createRandomPath();
	}

	int direction = _path.top().first;
	float speed = _path.top().second;
	_path.pop();

	updatePosition(direction, speed);		
}
*/


bool GoldenSnitch::newMovementIsParasite(int parasitesRate) {
	int isParasite = rand()%100;
	if (isParasite < parasitesRate) {
		return true;
	} else {
		return false;
	}
}



void GoldenSnitch::flee() {
	glm::vec3 charPos = _character->getPosition();
	glm::vec3 snitchPos = this->getPosition();

	glm::vec3 diff = charPos-snitchPos;


	bool isParasite = newMovementIsParasite(5);

	if (isParasite) {
		int newDir = rand()%6;
		_path.push( std::make_pair(newDir, PARASITE_SPEED));
	}
	else 
	{
		if (diff.x < diff.y) {
			int newDir = rand()%2;
		} else {
			int newDir = rand()%2+2;
		}

		int newDir = 1;
		_path.push( std::make_pair(newDir, MAIN_SPEED));
	}

}


void GoldenSnitch::createRandomPath() {
	int n = rand()%100 + 1000;
	int newDir = rand()%6;

	for (int i=0 ; i<n ; i++) {
		int isParasite = newMovementIsParasite(5);

		if (isParasite) {
			newDir = rand()%6;
			_path.push( std::make_pair(newDir, PARASITE_SPEED));
		}
		else 
		{
			_path.push( std::make_pair(newDir, MAIN_SPEED));
		}
	}
}




void GoldenSnitch::updatePosition(int direction, float speed) {

	std::cout << "cc " << direction << " " << speed << std::endl;

	switch (direction) {
		// GO RIGHT
		case 0:
		_position.x += speed;
		//_angle.x += glm::half_pi<float>();
		break;

		// GO LEFT
		case 1:
		_position.x -= speed;
		//_angle.x -= glm::half_pi<float>();
		break;

		// GO UP
		case 2:
		_position.y += speed;
		break;

		// GO DOWN
		case 3:
		_position.y -= speed;
		break;

		// GO FORWARD
		case 4:
		_position.z += speed;
		break;

		// GO FORWARD
		default:
		_position.z -= speed;
		break;
	}

}






void GoldenSnitch::draw(long int t) {

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, *_texture);
	glUseProgram(*_shader);
	glUniform1i(glGetUniformLocation(*_shader, "textureBalai"), 0);
	

	GLuint modelTag = glGetUniformLocation(*_shader, "model");
	GLuint viewTag = glGetUniformLocation(*_shader, "view");
	GLuint projectionTag = glGetUniformLocation(*_shader, "projection");

	glm::mat4 view(_camera->getViewMatrix());
	glm::mat4 projection(glm::perspective(_camera->getZoom(), (float)1000/(float)800, 0.1f, 1000.0f));

	glm::mat4 model;
	model = glm::translate(model, _position);
	model = glm::rotate(model, _angle.x, glm::vec3(1.f, 0, 0));
	model = glm::rotate(model, _angle.y, glm::vec3(0, 1.f,0));
	model = glm::rotate(model, _angle.z, glm::vec3(0, 0, 1.f));
	glUniformMatrix4fv(modelTag, 1, GL_FALSE, glm::value_ptr(model));


	glUniformMatrix4fv(viewTag, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionTag, 1, GL_FALSE, glm::value_ptr(projection));
	

	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, _mesh->getNbIndices(), GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}
