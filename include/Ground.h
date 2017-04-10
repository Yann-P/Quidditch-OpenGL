/**
  *	@author Yann Pellegrini
  */

#ifndef __GROUND_H__
#define __GROUND_H__

#include <Drawable.h>
#include <Camera.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>
#include <cstdlib>
#include <stack>


class Ground: public Drawable {
public:
	explicit Ground();
	void update(long int) override;
	void draw(long int) override;
	Ground(const Ground&) = delete;

private:
	

};


#endif