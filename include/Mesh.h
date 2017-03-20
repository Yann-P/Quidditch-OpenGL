#ifndef MESH_H
#define MESH_H


class Mesh
{
    public:
        Mesh();
        ~Mesh();
        Mesh(const Mesh& other);
        Mesh& operator=(const Mesh& other);
    protected:
    private:
        float* _positions;
        int* _indices;
};

#endif // MESH_H
