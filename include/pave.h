/* -*- mode: c++ -*- */

/*
 * @name : obstacle.h
 * @author : vtran
 */

#ifndef PAVE.H
#define PAVE.H

#include "obstacle.h"

class Pave : public Obstacle{
public:
    vec3 _baseCenterPosition;
    int _heigh;
    int _width;
    int _lenght;
    vec3 _direction; //unused
    vec3 _rotation; //unused

    Obstacle(vec3, int, int, int);
    ~Obstacle();

    detectCollision(vec3 object);


private:


};

#endif
