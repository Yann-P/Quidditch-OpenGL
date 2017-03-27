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
    ~Fleche();

    vec3 getDirection();
    void updateDirection(vec3 playerPosition, vec3 snitchPosition);

private:

    vec3 _direction;

};

#endif
