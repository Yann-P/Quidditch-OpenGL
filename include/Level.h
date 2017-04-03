/*
 *  @author Pierrick Bouvier
 *  @author Yann Pellegrini
 */

#ifndef LEVEL_H
#define LEVEL_H
#include <Drawable.h>
#include <Input.h>
#include <sys/time.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

class Level
{
    public:
        /** @brief  Creates an empty level
          */
        explicit Level();

        /** @brief  Called at each frame. Clears the screen, updates and draws each elements, swaps the buffer.
          */
        void frame() const;

        /** @brief  Adds a drawable object to be updated and drawn at every frame.
          * @param  The pointer to the Drawable object
          * @return 
          */
        void add(Drawable * const);


        /** @brief  Reçoit les évènements clavier
          */
        void key_callback(GLFWwindow*, int, int, int, int);

        /** @brief  Forbids copy
          */
        Level(const Level&) = delete;


        //bool collisionWithObstacle() const; // À DÉBUGGER!

    protected:
    private:
    	long int elapsed() const;
    	long int _startTime;
        std::vector<Drawable *> _drawables;
        Camera _camera;
        Input _input;
        bool _win = false;
        // Character * _character;
        // GoldenSnitch * _snitch;




};

#endif
