/*
 *  @author Pierrick Bouvier
 *  @author Yann Pellegrini
 */

#ifndef LEVEL_H
#define LEVEL_H
#include <Drawable.h>
#include <obstacle.h>
#include <character.h>
#include <Input.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

class Level
{
public:
	/** @brief  Creates an empty level
		*/
	explicit Level(const std::string &);

	/** @brief  Init context
		*/
    void init();

	/** @brief  Called at each frame. Clears the screen, updates and draws each elements, swaps the buffer.
		*/
	void frame();

	/** @brief  Adds a drawable object to be updated and drawn at every frame.
		* @param  The pointer to the Drawable object
		* @return
		*/
	void add(Drawable * const);


	/** @brief  Reçoit les évènements clavier
		*/
	void key_callback(GLFWwindow*, int, int, int, int);


	/** @brief charge les obstacles de la map. requiert le personnage **/
	void load(Character *);


	/** @brief  Forbids copy
		*/
	Level(const Level&) = delete;


	//bool collisionWithObstacle() const; // À DÉBUGGER!

protected:
private:
	void loadMap(const std::string &);

	long int _startTime;
	std::vector<Drawable *> _drawables;
	Camera _camera;
	Input _input;
	bool _win = false;

	int _width;
	int _height;
	std::vector<std::vector<int>*> _obstaclesData;
	// Character * _character;
	// GoldenSnitch * _snitch;



};

#endif
