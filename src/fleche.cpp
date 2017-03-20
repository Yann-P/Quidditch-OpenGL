/*
 * @name : fleche.cpp
 * @author : vtran
 */

#include "../include/fleche.h"
#include <stdio.h>
using namespace std;

Fleche::Fleche(){
    cout << "++Fleche()" << endl;
}

Fleche::~fleche(){
    cout << "--Fleche()" << endl;
}

vec3 Fleche::getDirection(){
    cout << "getDirection()" << endl;
    return _direction;
}

Fleche::updateDirection(vec3 playerPosition, vec3 snitchPosition){
    cout << "updateDirection()" << endl;
    _direction = snitchPosition - playerPosition;
}

