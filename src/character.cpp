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
  _speed = glm::vec3(1,1,1);
  _maxSpeed = 5;
  _accel = glm::vec3(1.1,1.1,1.1);
}

glm::vec3 Character::getSpeed(){
  return _speed;
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
    _speed.x -= _accel.x;
  }
        
  if(_input->isDown(GLFW_KEY_D)){
    //cout << "droite ";
    _speed.x += _accel.x;
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

  if(_input->isDown(GLFW_KEY_W)){  //z
    //cout << "avant ";
    _speed.y += _accel.y;
  }

  if(_input->isDown(GLFW_KEY_S)){
    //cout << "arriere ";
    _speed.y += _accel.y;
  }

  if(_input->isDown(GLFW_KEY_LEFT_SHIFT)){
    //cout<< "brake"
    _speed /= _accel;
  }

  if(_input->isDown(GLFW_KEY_SPACE)){
    //cout<< "accel"
    if(speedLimit()){
      _speed *= _accel;
    }
  }


  /* mouvement continue*/
  _position += _speed;


}

void Character::accel(){
  int acc = 0;
  acc += _accel.x;
  acc += _accel.y;
  acc += _accel.z;
}

bool Character::speedLimit(){
  float acc = 0.0;
  //acc += _speed*_speed;
  return (acc < _maxSpeed);
}