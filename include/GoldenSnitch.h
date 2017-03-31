/**
 * \file GoldenSnitch.h
 * \author Julien Lepasquier
 * \date 20/03/2017
 *
 */

#ifndef GOLDENSNITCH_H
#define GOLDENSNITCH_H



#define SNITCH_MAX_SPEED 10

#include <glm/glm.hpp>

class GoldenSnitch {
private:
	glm::vec3 _position;

	glm::vec3 _forward;
	glm::vec3 _up;
	glm::vec3 _right;

	float _speed;
	float _scale;


public:
	GoldenSnitch();
	~GoldenSnitch();
	void draw();
	void update(float dt);

	glm::vec3 getPosition();
	float getSpeed();

};


#endif
