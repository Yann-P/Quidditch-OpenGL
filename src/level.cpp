/*
 * Classe level
 * @file : level.cpp
 * @author : Pierrick Bouvier
 * @brief :
 *
 * @date 20 march 2017
 *
 */

#include "level.h"
#include "obstacle.h"
#include <glm/glm.hpp>
using namespace std;

Level::Level(){
  _seeker = new Character();
  _gsnitch = new GoldenSnitch();
  _win = false;

}

//Level::~Level(){
//
//  for(int i=0; i<_obstacles.size();i++){
//    _obstacles[i].~Obstacles();
//  }
//}

glm::vec3 Level::getCharacterSpeed(){
  return _seeker->getSpeed();
}

float Level::getSnitchSpeed(){
  return _gsnitch->getSpeed();
}


void Level::start(){

}

void Level::newGame(){

}


bool Level::collisionWithObstacle(){

  vector<Obstacle>::iterator itBegin= _obstacles.begin();
  vector<Obstacle>::iterator itEnd= _obstacles.end();

  while(itBegin!=itEnd){
    if(!((*itBegin).detectCollision(_seeker->getPosition()) ) )
      {
	return true;
      }
    ++itBegin;
  }
}
