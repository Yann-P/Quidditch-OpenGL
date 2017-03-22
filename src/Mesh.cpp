#include "Mesh.h"

Mesh::Mesh(float* positions, unsigned int *indices)
{
    _positions = positions;
    _indices = indices;
}

Mesh::Mesh(const Mesh& other)
{
    memcpy(this, &other, sizeof(Mesh));
}

Mesh& Mesh::operator=(const Mesh& other)
{
    if (this == &other)
        return *this;
    memcpy(this, &other, sizeof(Mesh));
    return *this;
}

float* Mesh::getPositions()
{
    return _positions;
}

unsigned int* Mesh::getIndices()
{
    return _indices;
}

Mesh::~Mesh()
{
    delete _positions;
    delete _indices;
}
