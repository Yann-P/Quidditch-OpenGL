/* -*- mode: c++ -*- */

/*
 * @name : level.h
 * @author : Pierrick BOUVIER
 * @brief :
 *
 *
 */

#ifndef LEVEL_H
#define LEVEL_H

#include "character.h"
#include "GoldenSnitch.h"
#include "obstacle.h"
#include <vector>
#include <glm/glm.hpp>

class Level{
private:
  Character* _seeker;
  GoldenSnitch* _gsnitch;
  std::vector<Obstacle> _obstacles;

  bool _win;

public:
  Level();
  ~Level();

  glm::vec3 getCharacterSpeed();
  float getSnitchSpeed();

  void start();
  void newGame();



  void draw();

  bool collisionWithObstacle();
  bool collisionWithGoldenSnitch();







};



#endif
