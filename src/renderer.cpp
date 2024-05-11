#include "renderer.h"


Renderer * Renderer::getInstance()
{
    if(m_renderer==nullptr)
    {
        m_renderer = new Renderer();
    }
    return m_renderer;
}

void Renderer::freeRenderer()
{
    delete m_renderer;
}

void Renderer::addModel(Model * model)
{
    m_models.push_back(model);
}

void Renderer::removeModel(Model * model)
{
    m_models.erase(std::remove(m_models.begin(), m_models.end(), model), m_models.end());
}

void Renderer::render()
{
    for(auto model : m_models)
    {
        model->bindVAO();
        model->draw();
    }
}

Renderer::~Renderer()
{
    delete m_renderer;
}

Renderer* Renderer::m_renderer = nullptr;
std::vector<Model*> Renderer::m_models{};
