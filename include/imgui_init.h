#ifndef IMGUI_INIT_H
#define IMGUI_INIT_H
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "glfw/glfw3.h"
#include <iostream>
class IMGUI
{
public:
    IMGUI(GLFWwindow* window);
    ~IMGUI();
    void IMGUIStart();
    void IMGUIRender();
    void renderUI(float &f);
private:
};
#endif