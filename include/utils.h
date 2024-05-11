#ifndef UTILS_H
#define UTILS_H
#include <glm/glm.hpp>
#include <string>

typedef struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texture;
} Vertex;

typedef struct Texture
{
    unsigned int id;
    std::string type;
};

#endif