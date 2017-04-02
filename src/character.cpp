/*
 * Classe character
 * @file : character.cpp
 * @author : Pierrick Bouvier
 * @brief :
 *
 *
 *
 */

#include "character.h"
#include <glm/glm.hpp>

Character::Character(){ // TODO FAIRE HÉRITER DE DRAWABLE
  _position = glm::vec3(0,0,0);
  _speed = glm::vec3(0,0,0);
  _maxSpeed = 30;
  _accel = glm::vec3(0,0,0);
}

glm::vec3 Character::getPosition(){
  return _position;
}

glm::vec3 Character::getSpeed(){
  return _speed;
}

void Character::draw(){
}

void Character::update(){
}

void Character::accel(){
}
