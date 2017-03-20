/*
 * Classe character
 * @name : character.cpp
 * @author : Pierrick Bouvier
 * @brief :
 *
 *
 *
 */

public Character::Character(){
  _position = vec3(0,0,0);
  _speed = vec3(0,0,0);
  _maxSpeed = 30;
  _accel = vec3(0,0,0);
}

vec3 Character::getPosition(){
  return _position;
}

vec3 Character::getSpeed(){
  return _speed;
}

void Character::draw(){
}

void Character::update(){
}

void Character::accel(){
}
