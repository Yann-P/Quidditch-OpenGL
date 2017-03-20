#include "Mesh.h"

Mesh::Mesh(float* positions, unsigned int *indices)
{
    _positions = positions;
    _indices = indices;
}

Mesh::Mesh(const Mesh& other)
{
    memcpy(this, &other, sizeof(Mesh));
    memcpy(this, &other, sizeof(Mesh));
}

Mesh& Mesh::operator=(const Mesh& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


Mesh::~Mesh()
{
    //dtor
}
