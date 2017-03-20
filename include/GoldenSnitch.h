/**
 * \file GoldenSnitch.h
 * \author Julien Lepasquier
 * \date 20/03/2017
 *
 */ 

#ifndef GOLDENSNITCH_H
#define GOLDENSNITCH_H


class GoldenSnitch {
private:
	Vector3 _position;
	Vector3 _speed;
	Vector3 _rotation;
	float _scale;


public:
	GoldenSnitch();
	~GoldenSnitch();
	void draw();
	void update();

	Vector3 getPosition();
	Vector3 getSpeed();

};


#endif