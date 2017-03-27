/*
 * @name : pave.cpp
 * @author : vtran
 */

#include "../include/pave.h"
#include <stdio.h>
using namespace std;


Pave::Obstacle(vec3 baseCenter, int heigh, int width, int lenght){
    _heigh = heigh; // hauteur y
    _width = width; // largeur x
    _lenght = lenght; // longueur z
    _baseCenterPosition = baseCenter; // position du centre de la face du bas
}


bool Pave::detectCollision(vec3 object){
    cout << "detectCollision()" << endl;
    if (object.y>=_baseCenterPosition.y
            && object.y<=_baseCenterPosition+_heigh
            && object.x>=_baseCenterPosition-_width/2
            && object.x<=_baseCenterPosition+_width/2
            && object.z>=_baseCenterPosition-_lenght/2
            && object.z<=_baseCenterPosition+_lenght/2){
        return true;
    }
    return false;
}
