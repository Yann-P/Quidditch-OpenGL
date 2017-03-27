/* -*- mode: c++ -*- */

/*
 * @name : character.h
 * @author : Pierrick BOUVIER
 * @brief : 
 *
 *
 */

#ifndef CHARACTER.H
#define CHARACTER.H


class Character{
 private:
  vec3 _position;
  int _maxSpeed;
  vec3 _accel;
  vec3 _speed;

public:
  character();
  vec3 getPosition();
  vec3 getSpeed();
  void draw();
  void update();
  void accel();

}

#endif
