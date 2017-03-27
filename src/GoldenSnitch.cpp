/**
 * \file GoldenSnitch.cpp
 * \author Julien Lepasquier
 * \date 20/03/2017
 *
 */ 

#include "GoldenSnitch.h"


GoldenSnitch::GoldenSnitch() {
	vec3 _position = {0,0,0};
	float _speed = 1;
	vec3 _rotation = {0,0,0};
	float _scale =  1;
}


GoldenSnitch::~GoldenSnitch() {
	
}


void GoldenSnitch::_update(float dt) {

	speed *= 0.96; // Friction in space, suuuure...

	/*
	 * @TODO : pour ralentir ou acceler
	 *
	 * static const float acceleration = 70;
	 *
	 * if (...) {
	 *	speed += dt * acceleration;
	 * }
	 *
	 * if (...) {
	 * 	speed -= dt * acceleration;
	 * }
	 */

	int movement = rand() % 4;


	_forward = _forward * cosf(rotationZ) + _right * sinf(rotationZ);
	_right = _forward.cross(_up);

	_right = _right * cosf(rotationY) + _up * sinf(rotationY);
	_right.normalize();
	_up = _right.cross(_forward);
	_up.normalize();

	_forward = _forward * cosf(rotationX) + _up * sinf(rotationX);
	_forward.normalize();
	_up = _right.cross(_forward);
	_up.normalize();

	_position += _forward * speed;

}


void GoldenSnitch::draw() {
}


vec3 GoldenSnitch::getPosition() {
	return _position;
}


float GoldenSnitch::getSpeed() {
	return _speed;
}