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

#define PI 3.14159265359

using namespace std;

Character::Character(glm::vec3 position) : Drawable(
  new Shader("../shaders/character.v.glsl", "../shaders/character.f.glsl"),
  new Mesh("../blend/character_test.blend"),
  new Texture("../texture/texture_peut_etre.tga")
){
  _position = position;
  //_speed = glm::vec3(1,1,1);
  _speed = 0;
  _maxSpeed = 0.5;
  _accel = 0.05;
  _n = 100;
  _alpha = (2 * PI) / (float) _n;
  _beta = (2 * PI) / (float) _n;
  _teta = PI / (float) 2;
  _phi = 0;
  _psy = _teta;
  _epsilon = _phi;
  _angle.y += 3.14;
  _dir = glm::vec3(cos(_phi)*cos(_teta),/*sin(_phi)*/0,-cos(_phi)*sin(_teta)); //direction dans la quelle regarde le personnage vitesse selon cette axe
  _up = glm::vec3(-sin(_phi)*cos(_teta),cos(_phi),sin(_phi)*sin(_teta));
  _right = glm::vec3(sin(_teta), 0 , -cos(_teta) );
  _left = glm::vec3(-sin(_teta), 0 , cos(_teta) ); //pas utile mais on sait jamais.
  cout << "x=" << _dir.x << " y=" << _dir.y << " z=" << _dir.z << endl;
}

float Character::getSpeed(){
  return _speed;
}

void Character::updateDir(){
  _dir = glm::vec3(cos(_epsilon)*cos(_psy),/*sin(_epsilon)*/0,-cos(_epsilon)*sin(_psy));
  _right = glm::vec3(sin(_psy), 0 , -cos(_psy) );
  //_left = glm::vec3(-sin(_psy), 0 , cos(_psy) ); //détail à regler ultérieurement
  _up = glm::vec3(-sin(_epsilon)*cos(_psy),cos(_epsilon),sin(_epsilon)*sin(_psy));

}

void Character::draw(long int t){
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, *_texture);
  glUseProgram(*_shader);
  glUniform1i(glGetUniformLocation(*_shader, "textureBalai"), 0);


  GLuint modelTag = glGetUniformLocation(*_shader, "model");
  GLuint viewTag = glGetUniformLocation(*_shader, "view");
  GLuint projectionTag = glGetUniformLocation(*_shader, "projection");

  _camera->updateCameraVectors();
  glm::mat4 view(_camera->getViewMatrix());
  glm::mat4 projection(glm::perspective(_camera->getZoom(), (float)1000/(float)800, 0.1f, 1000.0f));

  glm::mat4 model;
  

  model = glm::translate(model, _position);
  //model = glm::rotate(model, -_angle.x, _right);
  model = glm::rotate(model, _angle.y, _up);








  //model = glm::rotate(model, _angle.z, glm::vec3(0, 0, 1.f));
  //glRotatef( 3.14 , 0,1,0 );
  //glRotatef( 3.14 , 0,1,0 );
  /*quat Quaternion_teta;
  quat Quaternion_beta;
  Quaternion_teta = quat( _angle.x , _left);
  Quaternion_beta = quat( _angle.y , _up);

  glm::mat4 RotationMatrix = quaternion::toMat4(Quaternion_teta);
  glm::mat4 RotationMatrix = quaternion::toMat4(Quaternion_beta);*/
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
    _camera->Yaw -= _alpha * 360 / (2*PI) ;
    _angle.y += _alpha;
  }

  if(_input->isDown(GLFW_KEY_D)){
    //cout << "droite ";
    _psy -= _alpha;
    _camera->Yaw += _alpha * 360 / (2*PI);
    _angle.y -= _alpha;
  }

  if(_input->isDown(GLFW_KEY_W)){  //z
    //cout << "orientation basse";

    _position.y -= 0.1;

    /*_epsilon -= _beta;
    _angle.x -= _beta;
    _camera->Pitch -= _beta * 360 / (2*PI);*/
    //_angle.z -= abss(_dir.z)*_beta;
    //_angle.x = -sin(_epsilon)*cos(_psy);
    //_angle.z = sin(_epsilon)*sin(_psy);
  }

  if(_input->isDown(GLFW_KEY_S)){
    //cout << "orientation haute";

    _position.y += 0.1;
    /*
    _epsilon += _beta;
    _angle.x += _beta;
    _camera->Pitch += _beta * 360 / (2*PI);*/
    //_angle.z += abss(_dir.z)*_beta;
    //_angle.x = -sin(_epsilon)*cos(_psy);
    //_angle.z = sin(_epsilon)*sin(_psy);
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

  if(_input->isDown(GLFW_KEY_F)){
    cout << "teta=" << _psy << " phi=" << _epsilon << endl;
    cout << "up.x=" << _up.x << " up.y=" << _up.y << " up.z=" << _up.z << endl;  // up bouge avec la rotation selon son axe
    cout << "right.x=" << _right.x << " right.y=" << _right.y << " right.z=" << _right.z << endl;
    cout << "x=" << _dir.x << " y=" << _dir.y << " z=" << _dir.z << endl;

    endl(cout);
    endl(cout);
  }

  if(_input->isDown(GLFW_KEY_R)){ //pour le test à enlever après
    //cout << "reinitialisation de la position et direction";
    _dir = glm::vec3(cos(_phi)*cos(_teta),sin(_phi),-cos(_phi)*sin(_teta));
    _position = glm::vec3(-2, 5, -10);
    _psy = _teta;
    _epsilon = _phi;
    _speed = 0;
    _camera->Yaw = -90 ;
    _camera->Pitch = 0;
    _angle.y = 3.14;
    _angle.x = 0;
  }

  _camera->setPosition(_position - glm::vec3(10,10,10) * _dir /*glm::vec3(0,0,10.0)*/);
  
  
}

void Character::accel(){
}

bool Character::speedLimit(){
  return (_speed < _maxSpeed);
}


float Character::abss(float a){
  if(a<0){
    return -a;
  }
  return a;
}
