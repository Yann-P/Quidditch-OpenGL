#ifndef MESH_H
#define MESH_H

// #include <cstring>
#include <iostream>
#include <vector>
// #include <GL/glew.h>
// #include <GL/gl.h>
// #include <fstream>
// #include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm/glm.hpp>

class Mesh
{
    public:
        Mesh(const std::vector<glm::vec3>, const std::vector<int>);
        Mesh(const std::string &);
        const std::vector<glm::vec3> & getPositions() const;
        const std::vector<glm::vec3> & getNormals() const;
        const std::vector<glm::vec2> & getUvs() const;
        const std::vector<int> & getIndices() const;



    protected:


    private:
        std::vector<glm::vec3> _positions;
        std::vector<glm::vec3> _normals;
        std::vector<glm::vec2> _uvs;
        std::vector<int> _indices;

};

#endif // MESH_H
