/* -*- mode: c++ -*- */

/*
 * @name : level.h
 * @author : Pierrick BOUVIER
 * @brief : 
 *
 *
 */

#ifndef LEVEL.H
#define LEVEL.H

#include "character.h"
#include "goldensnitch.h"
#include "obstacle.h"
#include <Vector>

class Level{
private:
  Character _seeker;
  GoldenSnitch _gsnitch;
  std::Vector<Obstacle> _obstacles;

  bool _win;
  
public:
  Level();
  ~Level();

  vec3 getCharacterSpeed();
  vec3 getSnitchSpeed();
  
  void start();
  void newGame();



  void draw();
  
  bool collisionWithObstacle();
  bool collisionWithGoldenSnitch();
  
  
  
  
  
  
  
}



#define LEVEL.H
