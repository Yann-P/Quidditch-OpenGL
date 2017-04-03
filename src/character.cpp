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
#include <iostream>

using namespace std;

Character::Character(glm::vec3 position) : Drawable(
  new Shader("../shaders/character.v.glsl", "../shaders/character.f.glsl"),
  new Mesh("../blend/character_test.blend"),
  new Texture("../texture/texture_peut_etre.tga")
){
  _position = position;
  //_speed = glm::vec3(1,1,1);
  _speed = 0;
  _maxSpeed = 2;
  _accel = 1;
  _n = 100;
  _alpha = (2 * 3.14) / (float) _n;
  _beta = (2 * 3.14) / (float) _n;
  _teta = 3.14 / (float) 2;
  _phi = 0;
  _psy = _teta;
  _epsilon = _phi;
  _dir = glm::vec3(cos(_phi)*cos(_teta),sin(_phi),-cos(_phi)*sin(_teta)); //direction dans la quelle regarde le personnage vitesse selon cette axe

  cout << "x=" << _dir.x << " y=" << _dir.y << " z=" << _dir.z << endl;
}

float Character::getSpeed(){
  return _speed;
}

void Character::updateDir(){
  _dir = glm::vec3(cos(_epsilon)*cos(_psy),sin(_epsilon),-cos(_epsilon)*sin(_psy));
}

void Character::draw(long int t){
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

void Character::update(long int t){



  if(_input->isDown(GLFW_KEY_A)){  //q
    //cout << "gauche ";
    _psy += _alpha;
  }

  if(_input->isDown(GLFW_KEY_D)){
    //cout << "droite ";
    _psy -= _alpha;
  }

  if(_input->isDown(GLFW_KEY_W)){  //z
    //cout << "orientation basse";
    _epsilon -= _beta;
  }

  if(_input->isDown(GLFW_KEY_S)){
    //cout << "orientation haute";
    _epsilon += _beta;
  }


   /*
  if(_input->isDown(GLFW_KEY_Z)) {  //w
    //cout << "bas ";
    _position.y -= _speed.y;
  }

  if(_input->isDown(GLFW_KEY_X)){
    //cout << "haut ";
    _position.y += _speed.y;
  }*/

  if(_input->isDown(GLFW_KEY_LEFT_SHIFT)){
    //cout<< "brake"
    if(_speed<=0){
      _speed = 0;
    } else {
      _speed -= _accel;
    }
  }

  if(_input->isDown(GLFW_KEY_SPACE)){
    //cout<< "accel"
    if(speedLimit()){
      _speed += _accel;
    }
  } else {
    _speed *= 0.95;
  }


  /* mouvement continue*/
  updateDir();
  _position += _speed*_dir;

  _camera->setPosition(_position + glm::vec3(0,0,10.0));
}

void Character::accel(){
}

bool Character::speedLimit(){
  return (_speed < _maxSpeed);
}
