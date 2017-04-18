/*
 * @author Pierre Gabon
 */

#ifndef __DOME_H__
#define __DOME_H__

#include <Drawable.h>
#include <Camera.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>

/** @brief  The dome in the game. Implements Drawable.
  */

class Dome: public Drawable {
public:
	explicit Dome(glm::vec3);
	void update(long int) override;
	void draw(long int) override;
	Dome(const Dome&) = delete;


private:


};

#endif
