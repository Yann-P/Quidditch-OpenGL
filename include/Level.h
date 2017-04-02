/*
 *  @author Pierrick Bouvier
 *  @author Pierre Gabon
 *  @author Yann Pellegrini
 */

#ifndef LEVEL_H
#define LEVEL_H
#include <Drawable.h>
#include <sys/time.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

class Level
{
    public:
        /** @brief  Creates an empty level
          * @param  
          * @return 
          */
        Level();

        /** @brief  Called at each frame. Clears the screen, updates and draws each elements, swaps the buffer.
          * @param  
          * @return 
          */
        void frame() const;

        /** @brief  Adds a drawable object to be updated and drawn at every frame.
          * @param  The pointer to the Drawable object
          * @return 
          */
        void add(Drawable * const);

        /** @brief  Forbids copy
          */
        Level(const Level&) = delete;

    protected:
    private:
    	long int elapsed() const;

    	long int _startTime;
        std::vector<Drawable *> _drawables;


};

#endif
