#ifndef RENDERER_H
#define RENDERER_H
#include "model.h"
#include <vector>
class Renderer
{
public:

    static Renderer *getInstance();
    static void freeRenderer();
    static void addModel(Model* model);
    static void removeModel(Model* model);
    static void render();

	~Renderer();
private:
    static  Renderer *m_renderer;
    static std::vector<Model*> m_models;
    Renderer() = default;
};
#endif