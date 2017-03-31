/* -*- mode: c++ -*- */

/*
 * @name : character.h
 * @author : Pierrick BOUVIER
 * @brief :
 *
 *
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <glm/glm.hpp>


class Character{
 private:
  glm::vec3 _position;
  int _maxSpeed;
  glm::vec3 _accel;
  glm::vec3 _speed;

public:
  Character();
  glm::vec3 getPosition();
  glm::vec3 getSpeed();
  void draw();
  void update();
  void accel();

};

#endif
