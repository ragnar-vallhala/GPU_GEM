#ifndef MODEL_H
#define MODEL_H
#ifdef DEBUG
#include <iostream>
#endif
#include "shader.h"
class Model
{

public:
    Model();
    ~Model();
    void draw();
    void setVertex(const float* vertices, unsigned int count);
    void bindVAO();
    void loadShader(const char* vertexShaderPath, const char* fragmentShaderPath);
    bool isVertexAttribPointerSet();
	bool isVBOSet();
	bool isShaderSet();
    void setVBO();
    void SetAttribPointer(int attribIndex, int countOfValues, int stride, long long int offset);

private:
    const float* m_vertices;
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;
    unsigned int m_indices;
    unsigned int m_texture;
    unsigned int m_countOfVertices;
    bool m_isVertexAttribPointerSet=false;
	bool m_isVBOSet=false;
	bool m_isShaderSet=false;
    Shader* m_shader=nullptr;    
};


#endif