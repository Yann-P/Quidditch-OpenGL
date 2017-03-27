#ifndef OBJECTSTODRAW_H
#define OBJECTSTODRAW_H

#include <map>
class ObjectsToDraw
{
    public:
        ObjectsToDraw();
        ~ObjectsToDraw();
        void addVAO(std::string nom, const GLuint & vao);
        void addVBO(std::string nom, const GLuint & vbo);
        void addIBO(std::string nom, const GLuint & ibo);
        void addProgram(GLuint vao, const GLuint & program);
        std::map <std::string, GLuint> vaoList;
        std::map <std::string, GLuint> vboList;
        std::map <std::string, GLuint> iboList;
        std::map <GLuint, GLuint> programList;

    protected:
    private:


//        GLuint vaoField;
//        GLuint vaoCharacter;
//        GLuint vaoSnitch;
//        GLuint vaoObstacle;
//        GLuint vboPositionField;
//        GLuint vboTextureField;
//        GLuint vboPositionCharacter;
//        GLuint vboTextureCharacter;
//        GLuint vboPositionSnitch;
//        GLuint vboTextureSnitch;
//        GLuint programField;
//        GLuint programCharacter;
//        GLuint programSnitch;
//        GLuint programObstacle;

};

#endif // OBJECTSTODRAW_H
