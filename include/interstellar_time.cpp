#include "interstellar_time.h"

void InterstellarX::Time::Update()
{
    time = glfwGetTime();
    deltaTime = time - lastFrame;
    lastFrame = time;
}