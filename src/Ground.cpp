#include <Ground.h>
#include <iostream>

using namespace std;

Ground::Ground() : Drawable (
	new Shader("../shaders/ground.v.glsl", "../shaders/ground.f.glsl"),
	new Mesh("../blend/plane.blend"),
	new Texture("../texture/gazon.tga")
) {
	_position = glm::vec3(-500, 0, -500);
	_angle = glm::vec3(89.5099, 3.16, 0);
}

void Ground::update(long int) {
}


void Ground::draw(long int) {
    glDisable(GL_CULL_FACE);

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

    model = glm::scale(model, glm::vec3(1000, 1000, 1));

    glUniformMatrix4fv(modelTag, 1, GL_FALSE, glm::value_ptr(model));


    glUniformMatrix4fv(viewTag, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionTag, 1, GL_FALSE, glm::value_ptr(projection));


    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, _mesh->getNbIndices(), GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);

    glEnable(GL_CULL_FACE);

}