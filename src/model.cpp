#include "model.h"

Model::Model()
{
    glGenVertexArrays(1,&m_VAO);
    glGenBuffers(1, &m_VBO);
}

void Model::draw()
{
    if(m_shader==nullptr)
    {
        #ifdef DEBUG
        std::cout<<"Shader not loaded on model."<<std::endl;
        #endif
        return;
    }
    else if(! (m_isShaderSet && m_isVBOSet && m_isVertexAttribPointerSet))
    {
        #ifdef DEBUG
        std::cout<<"Attributes not set properly."<<std::endl;
        #endif
        return;
    }
    bindVAO();
    m_shader->useProgram();
    glDrawArrays(GL_TRIANGLES, 0, 2*9);

}

void Model::setVertex(const float *vertices, unsigned int count)
{
    m_vertices =(float *)vertices;
    m_countOfVertices = count;
}

void Model::loadShader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    m_shader = new Shader(vertexShaderPath, fragmentShaderPath);
    m_isShaderSet = true;
}

void Model::setVBO()
{
    bindVAO();
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*m_countOfVertices, m_vertices, GL_STATIC_DRAW);
	m_isVBOSet = true;
}

void Model::bindVAO()
{
   glBindVertexArray(m_VAO);
}

void Model::SetAttribPointer(int attribIndex, int countOfValues, int stride, long long int offset)
{
    bindVAO();
	glVertexAttribPointer(attribIndex, countOfValues, GL_FLOAT, GL_FALSE, stride, (const void*)offset);
	glEnableVertexAttribArray(attribIndex);
	m_isVertexAttribPointerSet = true;
}
