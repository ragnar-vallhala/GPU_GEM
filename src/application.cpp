#include "application.h"
Application::Application()
{
    this->m_windowHandler = new WindowHandler("Ragnar-Vallahala");
    this->m_imgui = new IMGUI(m_windowHandler->getWindow());
    this->m_graphicsCard = std::string((char*)glGetString(GL_RENDERER));
}

Application::~Application()
{
    delete m_windowHandler;
    delete m_imgui;
}

void Application::run()
{
    float f = 0;
    auto currentTime = std::chrono::system_clock::now();
    const float vertices[] = {
        0.0f, 0.5f, 0.0f,  1, 0, 0,
        0.5f, -0.5f, 0.0f, 0, 1, 0,
        -0.5f, -0.5f, 0.0f,0, 0, 1,
    };  
    Model *model = new Model();
    model->setVertex(vertices,sizeof(vertices) / sizeof(vertices[0]));
    model->setVBO();
    model->loadShader("../../shaders/triangle/vert.glsl", "../../shaders/triangle/frag.glsl");
    for(int i = 0; i < 2; i++)
        model->SetAttribPointer(i, 3, 6*sizeof(float), 3*sizeof(float)*i);
    Renderer* renderer = Renderer::getInstance();
    Renderer::addModel(model);

    while (!m_windowHandler->closeWindow())
    {
        m_imgui->IMGUIStart();
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_windowHandler->processInput();
        renderer->render();
        // m_imgui->renderUI(f);
        m_imgui->IMGUIRender();
        this->putFPS();
        glfwSwapBuffers(m_windowHandler->getWindow());
        glfwPollEvents();
    }
}

void Application::putFPS()
{
    auto diff = std::chrono::system_clock::now() - m_lastTime;
    float fps = 1/ (std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() / 1000.0f);
    m_lastTime = std::chrono::system_clock::now();
    glfwSetWindowTitle(m_windowHandler->getWindow(),("Ragnar-Vallhala\t" + std::to_string(fps)).c_str());
}
