#include "application.h"

Application::Application()
{
    m_windowHandler = new WindowHandler("Ragnar-Vallahala");
    m_imgui = new IMGUI(m_windowHandler->getWindow());
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
    while (!m_windowHandler->closeWindow())
    {
        m_imgui->IMGUIStart();
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_windowHandler->processInput();
        m_imgui->renderUI(f);
        m_imgui->IMGUIRender();
        {
            auto diff = std::chrono::system_clock::now() - currentTime;
            float fps = 1/ (std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() / 1000.0f);
            currentTime = std::chrono::system_clock::now();
            glfwSetWindowTitle(m_windowHandler->getWindow(),std::to_string(fps).c_str());
        }
        glfwSwapBuffers(m_windowHandler->getWindow());
        glfwPollEvents();
    }
}
