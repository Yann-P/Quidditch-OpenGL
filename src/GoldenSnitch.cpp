/**
 * \file GoldenSnitch.cpp
 * \author Julien Lepasquier
 * \date 20/03/2017
 *
 */

#include "GoldenSnitch.h"
#include <glm/glm.hpp>

GoldenSnitch::GoldenSnitch() { // TODO FAIRE HÉRITER DE DRAWABLE
	glm::vec3 _position = {0,0,0};
	float _speed = 1;
	glm::vec3 _rotation = {0,0,0};
	float _scale =  1;
}


GoldenSnitch::~GoldenSnitch() {

}


void GoldenSnitch::update(float dt) {

	_speed *= 0.96; // Friction in space, suuuure...

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

//
//	_forward = _forward * cosf(_rotationZ) + _right * sinf(_rotationZ);
//	_right = _forward.cross(_up);
//
//	_right = _right * cosf(rotationY) + _up * sinf(_rotationY);
//	_right.normalize();
//	_up = _right.cross(_forward);
//	_up.normalize();
//
//	_forward = _forward * cosf(rotationX) + _up * sinf(_rotationX);
//	_forward.normalize();
//	_up = _right.cross(_forward);
//	_up.normalize();
//
//	_position += _forward * _speed;

}


void GoldenSnitch::draw() {
}


glm::vec3 GoldenSnitch::getPosition() {
	return _position;
}


float GoldenSnitch::getSpeed() {
	return _speed;
}
