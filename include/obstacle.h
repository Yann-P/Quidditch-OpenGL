/* -*- mode: c++ -*- */

/*
 * @name : obstacle.h
 * @author : vtran
 */

#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include <Camera.h>
#include <Broom.h>
#include <character.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>

#include <glm/glm.hpp>
#include <Drawable.h>

class Obstacle: public Drawable{
public:

    bool detectCollision(glm::vec3);
    explicit Obstacle(glm::vec3);
    void update(long int) override;
    void draw(long int) override;
    void setCharacter(const Character *);  // TODO MODIFIER BROOM EN CHARACTER
    Obstacle(const Obstacle&) = delete;
    //Obstacle();

private:
    int _height=5;
    int _width=5;
    int _length=5;
    const Character * _character; // TODO MODIFIER BROOM EN CHARACTER

};

#endif
