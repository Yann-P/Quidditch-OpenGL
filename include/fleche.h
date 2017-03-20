/* -*- mode: c++ -*- */

/*
 * @name : fleche.h
 * @author : vtran
 */

#ifndef FLECHE.H
#define FLECHE.H

class Fleche{
public:

    Fleche();
    ~fleche();

    vec3 getDirection();
    void updateDirection(vec3 playerPosition, vec3 snitchPosition);

private:

    vec3 _direction;

};

#endif
