/**
  *  @author Yann Pellegrini
  *
  */



#include "Mesh.h"


Mesh::Mesh(const std::string & file) {

    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile(file, 
                                             aiProcess_Triangulate |
                                             aiProcess_GenSmoothNormals | 
                                             aiProcess_FlipUVs);

    if(!scene) {
        std::cerr << "Mesh::Mesh(const string &) : Mesh load failed! " << std::endl;
    }

    const aiMesh* model = scene->mMeshes[0];
    const aiVector3D aiZeroVector(0.0f, 0.0f, 0.0f);

    for(unsigned int i = 0; i < model->mNumVertices; i++) 
    {
        const aiVector3D* pos = &(model->mVertices[i]);
        const aiVector3D* nor = &(model->mNormals[i]);
        const aiVector3D* tex = model->HasTextureCoords(0) ? &(model->mTextureCoords[0][i]) : &aiZeroVector;
        
        _positions.push_back(glm::vec3(pos->x, pos->y, pos->z));
        _normals.push_back(glm::vec3(nor->x, nor->y, nor->z));
        _uvs.push_back(glm::vec2(tex->x, tex->y));

    }

    for(unsigned int i = 0; i < model->mNumFaces; i++)
    {
        const aiFace& face = model->mFaces[i];
        assert(face.mNumIndices == 3);
        _indices.push_back(face.mIndices[0]);
        _indices.push_back(face.mIndices[1]);
        _indices.push_back(face.mIndices[2]);
    }   


}


const std::vector<glm::vec3> & Mesh::getPositions() const { return _positions; }
const std::vector<glm::vec3> & Mesh::getNormals() const { return _normals; }
const std::vector<glm::vec2> & Mesh::getUvs() const { return _uvs; }
const std::vector<int> & Mesh::getIndices() const { return _indices; }
int Mesh::getNbIndices() const { return _indices.size(); }
