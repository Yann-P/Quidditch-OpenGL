#include <Broom.h>

Broom::Broom() : Drawable(
	Shader("../shaders/balai.v.glsl", "../shaders/balai.f.glsl"), 
	Mesh("../blend/balai.blend")
) {

}

void Broom::draw(long int t) {

	glUseProgram(_shader);

 	glm::mat4 projection = glm::frustum(-1., 1., -1., 1., 0.1, 100.); //  glm::mat4();
 	GLuint etq = glGetUniformLocation(_shader, "proj");
 	glUniformMatrix4fv(etq, 1, false, glm::value_ptr(projection));

 	glm::mat4 mv;
 	mv = glm::rotate(mv, (float)(t/1000.f), glm::vec3(0, 0, 1));
 	mv = glm::translate(mv, glm::vec3(0, 0, -1));

 	GLuint etq2 = glGetUniformLocation(_shader, "mv");

 	glUniformMatrix4fv(etq2, 1, false, glm::value_ptr(mv));
	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, _nbIndices, GL_UNSIGNED_INT, 0);

}