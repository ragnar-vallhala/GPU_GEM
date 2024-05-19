#ifndef MESHES_H
#define MESHES_H
#include <vector>
#include "shader.h"
#include "utils.h"
#include "glad/glad.h"
#include "glm/glm.hpp"

class Mesh
{    
public:
    Mesh(std::vector<Vertex> &vertices,std::vector<unsigned int> &indices, std::vector<Texture> textures);
    ~Mesh();
    std::vector<Vertex> m_vertices;
    std::vector<unsigned int> m_indices;
    std::vector<Texture> m_textures;
    void Draw(Shader &shader);
private:
    unsigned int m_VAO, m_VBO, m_EBO;
    void setupMesh();
};

#endif