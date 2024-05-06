#ifndef APPLICATION_H
#define APPLICATION_H
#include "window_handler.h"
#include "imgui_init.h"
#include <chrono>
#include <string>

class Application
{
public:
    Application();
    ~Application();
    void run();
private:
    WindowHandler *m_windowHandler = nullptr;
    IMGUI *m_imgui = nullptr;
};
#endif