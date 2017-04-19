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

    bool detectCollision(const glm::vec3 &);
    explicit Obstacle(int,int,int);
    void update(long int) override;
    void draw(long int) override;
    void setCharacter(Character *);
    Obstacle(const Obstacle&) = delete;

private:
    int _height;//=5;
    int _width=15;
    int _length=15;
    Character *  _character;
    static Mesh * _o_mesh;
};

#endif
