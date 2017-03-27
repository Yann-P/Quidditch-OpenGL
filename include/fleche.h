/* -*- mode: c++ -*- */

/*
 * @name : fleche.h
 * @author : vtran
 */

#ifndef FLECHE_H
#define FLECHE_H

class Fleche{
public:

    Fleche();

    int* getDirection();
    void updateDirection(int* playerPosition, int* snitchPosition);

private:

    int* _direction;

};

#endif
