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


class GoldenSnitch: public Drawable {
public:
	explicit GoldenSnitch(glm::vec3);
	void update(long int) override;
	void draw(long int) override;
	GoldenSnitch(const GoldenSnitch&) = delete;

private:
	std::stack<int> _path;

};


#endif
