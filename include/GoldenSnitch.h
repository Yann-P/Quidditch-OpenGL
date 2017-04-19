/**
 * \file GoldenSnitch.h
 * \author Julien Lepasquier
 * \date 20/03/2017
 *
 */

#ifndef GOLDENSNITCH_H
#define GOLDENSNITCH_H


#define SNITCH_MAX_SPEED 10

#include <Drawable.h>
#include <Camera.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <utility>
#include "character.h"
#include <math.h>


class GoldenSnitch: public Drawable {
public:
	explicit GoldenSnitch(glm::vec3);
	void update(long int) override;
	void draw(long int) override;

	void createRandomPath();
	void updatePosition(int direction, float speed);
    bool detectCollision(const glm::vec3 &);
	GoldenSnitch(const GoldenSnitch&) = delete;

	/* Fuir le char ??? */
	void setCharacter(const Character *);
	void flee();
	bool newMovementIsParasite(int parasitesRate);
	float getDistanceFromCharacter();

private:
	const Character * _character;
	std::stack< std::pair<int, float> > _path;
    bool _fixed;

};


#endif
