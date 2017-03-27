#ifndef MESH_H
#define MESH_H

#include <cstring>


class Mesh
{
    public:
        Mesh(float*, unsigned int*);
        Mesh(const Mesh& );
        Mesh& operator=(const Mesh& );

        float* getPositions();
        unsigned int * getIndices();

        ~Mesh();


    protected:


    private:
        float* _positions;
        unsigned int* _indices;

};

#endif // MESH_H
