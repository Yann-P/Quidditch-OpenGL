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
        Level();
        void drawLevel() const;
        void addDrawable(Drawable * const);

    protected:
    private:
    	void drawAllDrawables() const;
    	long int getTime() const;

    	long int _startTime;
        std::vector<Drawable *> _drawables;


};

#endif
