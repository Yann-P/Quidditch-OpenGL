/*
 * @author Yann Pellegrini
 */

#ifndef __BROOM_H__
#define __BROOM_H__

#include <Drawable.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
 #include <iostream>

class Broom: public Drawable {
public:
	Broom();
	void draw(long int) override;

private:


};

#endif
