/*
 * @name : fleche.cpp
 * @author : vtran
 */

#include "../include/fleche.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Fleche::Fleche(){
    cout << "++Fleche()" << endl;
}
/*
Fleche::~fleche(){
    cout << "--Fleche()" << endl;
}
*/
int* Fleche::getDirection(){
    cout << "getDirection()" << endl;
    return _direction;
}

void Fleche::updateDirection(int* playerPosition, int* snitchPosition){
    cout << "updateDirection()" << endl;
    //_direction = snitchPosition - playerPosition; //a finir plus tard
}

