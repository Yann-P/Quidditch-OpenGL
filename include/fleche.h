/* -*- mode: c++ -*- */

/*
 * @name : fleche.h
 * @author : vtran
 */
/*
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
*/

/* -*- mode: c++ -*- */

/*
 * @name : obstacle.h
 * @author : vtran
 */

#ifndef __ARROW_H__
#define __ARROW_H__

#include <Camera.h>
#include <GoldenSnitch.h>
#include <character.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>

#include <glm/glm.hpp>
#include <Drawable.h>

class Arrow: public Drawable{
public:

    explicit Arrow(glm::vec3);
    void update(long int) override;
    void draw(long int) override;
    void setCharacter(const Character *);
    void setGoldenSnitch(const GoldenSnitch *);
    Arrow(const Arrow&) = delete;
    //Obstacle();

private:
    const Character * _character;
    const GoldenSnitch * _goldensnitch;

};

#endif
