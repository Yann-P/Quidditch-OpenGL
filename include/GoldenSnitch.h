/**
 * \file GoldenSnitch.h
 * \author Julien Lepasquier
 * \date 20/03/2017
 *
 */ 

#ifndef GOLDENSNITCH_H
#define GOLDENSNITCH_H



#define SNITCH_MAX_SPEED 10


class GoldenSnitch {
private:
	vec3 _position;	

	Vector3 _forward;
	Vector3 _up;
	Vector3 _right;

	float _speed;
	float _scale;


public:
	GoldenSnitch();
	~GoldenSnitch();
	void draw();
	void update(float dt);

	vec3 getPosition();
	float getSpeed();

};


#endif