/*
 * @name : fleche.cpp
 * @author : vtran
 */

#include "../include/fleche.h"
#include <math.h>
#include <stdio.h>
using namespace std;



Arrow::Arrow(glm::vec3 position) : Drawable(
	new Shader("../shaders/balai.v.glsl", "../shaders/balai.f.glsl"),
	new Mesh("../blend/arrow.blend"),
	new Texture("../texture/texture_peut_etre.tga")

) {
	_position = position;

}

void Arrow::setCharacter(const Character * character) {
	_character = character;
}

void Arrow::setGoldenSnitch(const GoldenSnitch * goldensnitch) {
	_goldensnitch = goldensnitch;
}

void Arrow::update(long int t) {

	const glm::vec3 & snitchPos = _goldensnitch->getPosition();
	const glm::vec3 & charPos = _character->getPosition() + glm::vec3(0,10,0);
	glm::vec3 vect = glm::vec3( snitchPos.x-charPos.x , snitchPos.y-charPos.y , snitchPos.z-charPos.z);

	_angle.y = 0;
	_angle.x = M_PI/2 - atan(vect.y/ vect.z);//-atan(vect.y/ vect.z)+1.57;
	_angle.z = 4*M_PI/3 + atan(vect.z / vect.x) + M_PI/11;//atan(vect.z / vect.x)+1.57;
	
	if(vect.x<0){
		_angle.z += M_PI;
	}

	_position = charPos;

}


void Arrow::draw(long int t) {

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
	model = glm::rotate(model, _angle.z, glm::vec3(0, 0, 1.f));
	model = glm::rotate(model, _angle.y, glm::vec3(0, 1.f,0));
	model = glm::scale(model, glm::vec3(3, 3, 3));
	glUniformMatrix4fv(modelTag, 1, GL_FALSE, glm::value_ptr(model));


	glUniformMatrix4fv(viewTag, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionTag, 1, GL_FALSE, glm::value_ptr(projection));


	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, _mesh->getNbIndices(), GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}


