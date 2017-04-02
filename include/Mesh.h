/**
  *  @author Yann Pellegrini
  *
  */


#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm/glm.hpp>

class Mesh
{
    public:
        Mesh(const std::string &);
        const std::vector<glm::vec3> & getPositions() const;
        const std::vector<glm::vec3> & getNormals() const;
        const std::vector<glm::vec2> & getUvs() const;
        const std::vector<int> & getIndices() const;
        const int getNbIndices() const;
        Mesh(const Mesh&) = delete;



    protected:


    private:
        std::vector<glm::vec3> _positions;
        std::vector<glm::vec3> _normals;
        std::vector<glm::vec2> _uvs;
        std::vector<int> _indices;

};

#endif // MESH_H
