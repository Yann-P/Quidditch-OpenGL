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
  float getSpeed();
  void draw(long int) override;
  void update(long int)override;
  void accel();
  bool speedLimit();
  void updateDir();
  Character(const Character&) = delete;
  float abss(float);

 private:
  float _maxSpeed;
  float _accel;
  float _speed;
  glm::vec3 _dir;
  int _n;       // donne l'angle de rotation de alpha et beta
  float _alpha; // mouvement de dir selon (Ox,Oz)
  float _beta; // mouvement de dir selon (Ox,Oy)
  float _teta; // axe origine de dir selon (Ox,Oz) (peut etre optionnel depend de si on veut le garder pour revenir a une position initiale)
  float _phi; // axe origine de dir selon (Oy,Oz) (peut etre optionnel depend de si on veut le garder pour revenir a une position initiale)
  float _psy; // ecart actuel d'angle avec _teta psy = teta + k*alpha
  float _epsilon; // ecart actuel d'angle avec _phi epsilon = phi + p*beta

};

#endif
