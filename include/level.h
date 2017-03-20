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

class Level{
private:
  Character _seeker;
  GoldenSnitch _gsnitch;
  Obstacle<> _obstacles;

  bool win;
  
public:
  Level();
  ~Level();
  
  vec3 getCharacterSpeed();
  
  void start();
  void newGame();



  void draw();
  
  bool collisionWithObstacle();
  bool collisionWithGoldenSnitch();
  
  
  
  
  
  
  
}



#define LEVEL.H
