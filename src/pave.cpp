/*
 * @name : pave.cpp
 * @author : vtran
 */

#include "../include/pave.h"
#include <stdio.h>
#include <iostream>
using namespace std;


Pave::Pave(int baseCenter[3], int height, int width, int lenght){
    _height = height; // hauteur y (1)
    _width = width; // largeur x (0)
    _lenght = lenght; // longueur z (2)
    _baseCenterPosition = baseCenter; // position du centre de la face du bas
}


bool Pave::detectCollision(glm::vec3 object){
    cout << "detectCollision()" << endl;
    if (object[1]>=_baseCenterPosition[1]
            && object[1]<=_baseCenterPosition[1]+_height
            && object[0]>=_baseCenterPosition[0]-_width/2
            && object[0]<=_baseCenterPosition[0]+_width/2
            && object[2]>=_baseCenterPosition[2]-_lenght/2
            && object[2]<=_baseCenterPosition[2]+_lenght/2){
        return true;
    }
    return false;
}
