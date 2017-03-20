/*
 * @name : pave.cpp
 * @author : vtran
 */

#include "../include/pave.h"
#include <stdio.h>
using namespace std;





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
