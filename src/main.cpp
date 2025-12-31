#include <iostream>

#include "application.h"

int main()
{
    Application::Init();

    while (!glfwWindowShouldClose(Application::window->window))
    {
        Application::Update();
    }

    return 0;
}