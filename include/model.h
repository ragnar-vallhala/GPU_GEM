#ifndef MODEL_H
#define MODEL_H
#ifdef DEBUG
#include <iostream>
#endif
#include <vector>
#include <string>
#include "shader.h"
#include "meshes.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
class Model
{

public:
    Model(char *path)
    {
        loadModel(path);
    }
    void draw(Shader &shader);

private:
    // model data
    std::vector<Mesh> m_meshes;
    std::string m_directory;

    void loadModel(const std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                         std::string typeName);
};

#endif