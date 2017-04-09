/**
 * \file GoldenSnitch.cpp
 * \author Julien Lepasquier
 * \date 20/03/2017
 *
 */

#include "GoldenSnitch.h"


GoldenSnitch::GoldenSnitch(glm::vec3 position) : Drawable(
	new Shader("../shaders/snitch.v.glsl", "../shaders/snitch.f.glsl"),
	new Mesh("../blend/cube.blend"),
	new Texture("../texture/texture_peut_etre.tga")
) {
	_position = position;

}


void GoldenSnitch::update(long int t) {

	if (_path.size() == 0) {
		int n = rand()%30 + 1;
		int nextDir = rand()%6;

		for (int i=0 ; i<n ; i++) {
			_path.push(nextDir);
		}
	}

	int dir = _path.top();
	_path.pop();

	switch (dir) {
		// GO RIGHT
		case 0:
        _position.x += 0.01;
		//_angle.x += glm::half_pi<float>();
		break;

		// GO LEFT
		case 1:
        _position.x -= 0.01;
		//_angle.x -= glm::half_pi<float>();
		break;

		// GO UP
		case 2:
        _position.y += 0.01;
		break;

		// GO DOWN
		case 3:
        _position.y -= 0.01;
		break;

		// GO FORWARD
		case 4:
        _position.z += 0.01;
		break;


		// GO FORWARD
		default:
        _position.z -= 0.01;
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
