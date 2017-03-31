/* -*- mode: c++ -*- */

/*
 * @name : obstacle.h
 * @author : vtran
 */

#ifndef PAVE_H
#define PAVE_H

//#include "obstacle.h"
#include <glm/glm.hpp>

class Pave /*: public Obstacle*/{
public:
    int* _baseCenterPosition;
    int _height;
    int _width;
    int _lenght;

    Pave(int*, int, int, int);
    //~Pave();

    bool detectCollision(glm::vec3);


private:


};

#endif
