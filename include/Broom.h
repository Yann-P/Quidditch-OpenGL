/*
 * @author Yann Pellegrini
 */

#ifndef __BROOM_H__
#define __BROOM_H__

#include <Drawable.h>
#include <Camera.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>

/** @brief  The broom in the game. Implements Drawable.
  */

class Broom: public Drawable {
public:
	explicit Broom(glm::vec3);
	void update(long int) override;
	void draw(long int) override;
	Broom(const Broom&) = delete;


private:


};

#endif
