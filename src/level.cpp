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
using namespace std;

public Level::Level(){
  _seeker = new Character();
  _gsnitch = new GoldenSnitch();
  _win = false;
  
}

public Level::~Level(){
  for(int i=0; i<_obstacles.size();i++){
    _obstacles[i].~Obstacles();
  }
}

public vec3 Level::getCharacterSpeed(){
  return _seeker.getSpeed();
}

public vec3 Level::getSnitchSpeed(){
  return _gsnitch.getSpeed();
}


public void Level::start(){

}

public void Level::newGame(){

}

public void Level::Draw(){

}

public bool Level::collisionWithObstacle(){

  vector<int>::iterator begin= _obstacles.begin();
  vector<int>::iterator end= _obstacles.end();

  while(begin!=end){
    if(!(begin.detectCollision(_seeker.getPosition()) ) )
      {
	return true;
      }
    ++begin;
  }
}
