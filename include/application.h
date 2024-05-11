#ifndef APPLICATION_H
#define APPLICATION_H
#include "windowHandler.h"
#include "imgui_init.h"
#include "glad/glad.h"
#include <chrono>
#include <string>
#include "model.h"
#include "renderer.h"
class Application
{
public:
    Application();
    ~Application();
    void run();
    void putFPS();
private:
    WindowHandler *m_windowHandler = nullptr;
    IMGUI *m_imgui = nullptr;
    std::chrono::time_point<std::chrono::system_clock> m_lastTime;
    std::string m_graphicsCard;
};
#endif