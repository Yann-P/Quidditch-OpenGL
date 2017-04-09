/*
 * @name : obstacle.cpp
 * @author : vtran & ypellegrini
 */

#include "../include/obstacle.h"
#include <stdio.h>
using namespace std;

bool Obstacle::detectCollision(glm::vec3 object)
{
    if (object[1]>=_position[1]-_height/2
            && object[1]<=_position[1]+_height/2
            && object[0]>=_position[0]-_width/2
            && object[0]<=_position[0]+_width/2
            && object[2]>=_position[2]-_length/2
            && object[2]<=_position[2]+_length/2){
        return true;
    }
    return false;
}



Obstacle::Obstacle(glm::vec3 position) : Drawable(
    new Shader("../shaders/obstacle.v.glsl", "../shaders/obstacle.f.glsl"),
    new Mesh("../blend/cube.blend"),
    new Texture("../texture/texture_peut_etre.tga")
) {
    _position = position;

}
/*
void Obstacle::setCharacter(const Broom * broom) {
    _broom = broom;
}
*/
void Obstacle::setCharacter(const Character * character) {
    _character = character;
}

void Obstacle::update(long int t) {
    //cout << _character->getPosition().x;
    if(detectCollision(_character->getPosition()))
    {
    _angle.x+=0.1;
    _angle.z+=0.01;
    }

}


void Obstacle::draw(long int t) {

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


