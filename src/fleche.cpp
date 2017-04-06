/*
 * @name : fleche.cpp
 * @author : vtran
 */
/*
#include "fleche.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Fleche::Fleche(){
    cout << "++Fleche()" << endl;
}


int* Fleche::getDirection(){
    cout << "getDirection()" << endl;
    return _direction;
}

void Fleche::updateDirection(int* playerPosition, int* snitchPosition){
    cout << "updateDirection()" << endl;
    //_direction = snitchPosition - playerPosition; //a finir plus tard
}

*/
/*
 * @name : obstacle.cpp
 * @author : vtran & ypellegrini
 */

#include "../include/fleche.h"
#include <math.h>
#include <stdio.h>
using namespace std;





Arrow::Arrow(glm::vec3 position) : Drawable(
    new Shader("../shaders/obstacle.v.glsl", "../shaders/obstacle.f.glsl"),
    new Mesh("../blend/cube.blend"),
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
    /*int norm = sqrt(
                (((((_character->getPosition())[0]-_goldensnitch->getPosition())[0])*
            (_character->getPosition())[0]-_goldensnitch->getPosition())[0]) +
            (((((_character->getPosition())[1]-_goldensnitch->getPosition())[1])*
        (_character->getPosition())[1]-_goldensnitch->getPosition())[1]) +
            (((((_character->getPosition())[2]-_goldensnitch->getPosition())[2])*
        (_character->getPosition())[2]-_goldensnitch->getPosition())[2]));
    cout << norm << endl;*/
    _angle.x=-atan((_goldensnitch->getPosition()[1]-_character->getPosition()[1]) /
            (_goldensnitch->getPosition()[2]-_character->getPosition()[2]));

    _angle.y=-atan((_goldensnitch->getPosition()[2]-_character->getPosition()[2]) /
            (_goldensnitch->getPosition()[0]-_character->getPosition()[0]));

    /*_angle.z=atan((_goldensnitch->getPosition()[1]-_character->getPosition()[1]) /
            (_goldensnitch->getPosition()[0]-_character->getPosition()[0]));*/


    _position = _character->getPosition();
    //if (_character->getPosition().x)
    //int test = _character->getPosition().x;
//cout << _character->getPosition().x;

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


