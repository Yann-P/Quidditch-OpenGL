/*
 * @name : obstacle.cpp
 * @author : vtran & ypellegrini
 */

#include "../include/obstacle.h"
#include <stdio.h>
using namespace std;

Mesh * Obstacle::_o_mesh = new Mesh("../blend/wood_tower.blend");

Obstacle::Obstacle(int gX, int gZ, int size) : Drawable(
    new Shader("../shaders/balai.v.glsl", "../shaders/balai.f.glsl"),
    _o_mesh,
    new Texture("../texture/t_C.tga")
) {
    glm::vec3 position = glm::vec3(gX, size, gZ);
    _position = position + glm::vec3(0, 0, 0);
    _angle = glm::vec3(glm::radians(-90.f), 0.f, 0.f);
    _height = size * 70; // 1*

}

bool Obstacle::detectCollision(const glm::vec3 & object)
{
    if (object.y >= _position.y - _height*2/2
            && object.y <= _position.y + _height*2/2
            && object.x >= _position.x - _width/2
            && object.x <= _position.x + _width/2
            && object.z >= _position.z - _length/2
            && object.z <= _position.z + _length/2){
        return true;
    }
    return false;
}

void Obstacle::setCharacter(Character * character) {
    _character = character;
}

void Obstacle::update(long int t) {
    //cout << _character->getPosition().x;
    if(detectCollision(_character->getPosition())) {
        std::cout << "hit" << std::endl;
        //_angle.z+=0.1;
        //_position.x+=0.1;
        _character->makeCollision();
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
    glm::mat4 projection(glm::perspective(_camera->getZoom(), (float)1000/(float)800, 0.1f, 10000.0f));

    glm::mat4 model;
    model = glm::translate(model, _position);
    model = glm::rotate(model, _angle.x, glm::vec3(1.f, 0, 0));
    model = glm::rotate(model, _angle.y, glm::vec3(0, 1.f,0));
    model = glm::rotate(model, _angle.z, glm::vec3(0, 0, 1.f));


    model = glm::scale(model, glm::vec3(3.f, 3.f, 10.f)); // /5

    glUniformMatrix4fv(modelTag, 1, GL_FALSE, glm::value_ptr(model));


    glUniformMatrix4fv(viewTag, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionTag, 1, GL_FALSE, glm::value_ptr(projection));


    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, _mesh->getNbIndices(), GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);
}


