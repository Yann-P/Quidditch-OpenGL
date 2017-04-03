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
 
#include <Drawable.h>
#include <Camera.h>


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>



class Character : public Drawable {
 public:
  explicit Character(glm::vec3);
  glm::vec3 getSpeed();
  void draw(long int) override;
  void update(long int)override;
  void accel();
  Character(const Character&) = delete;

 private:
  int _maxSpeed;
  glm::vec3 _accel;
  glm::vec3 _speed;
  bool keys[1024];


};

#endif
