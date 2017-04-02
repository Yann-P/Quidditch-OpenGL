/**
  *  @author Yann Pellegrini
  *
  */


#include <Broom.h>

Broom::Broom() : Drawable(
	new Shader("../shaders/balai.v.glsl", "../shaders/balai.f.glsl"),
	new Mesh("../blend/balai.blend"),
	new Texture("../texture/texture_peut_etre.tga")
){

}

void Broom::draw(long int t) {

	//std::cout << "shader : " << *_shader << std::endl;
	//std::cout << "_nbIndices : " << _mesh->getNbIndices() << std::endl;

	glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, *_texture);
    glUseProgram(*_shader);
    glUniform1i(glGetUniformLocation(*_shader, "textureBalai"), 0);

	

 	glm::mat4 projection = glm::frustum(-1., 1., -1., 1., 0.1, 100.);

 	
 	GLuint etq = glGetUniformLocation(*_shader, "proj");
 	glUniformMatrix4fv(etq, 1, false, glm::value_ptr(projection));

 	glm::mat4 mv;
 	mv = glm::rotate(mv, (float)(t/1000.f), glm::vec3(0, 0, 1));
 	mv = glm::translate(mv, glm::vec3(0, 0, -1));

 	GLuint etq2 = glGetUniformLocation(*_shader, "mv");
 	glUniformMatrix4fv(etq2, 1, false, glm::value_ptr(mv));

	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, _mesh->getNbIndices(), GL_UNSIGNED_INT, 0);

}