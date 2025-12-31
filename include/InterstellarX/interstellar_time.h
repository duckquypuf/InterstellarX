#pragma once

#include <GLFW/glfw3.h>

namespace InterstellarX::Time {
    inline float time = 0.0f;
    inline float deltaTime = 0.0f;
    inline float lastFrame = 0.0f;

    inline void Update() {
        time = glfwGetTime();
        deltaTime = time - lastFrame;
        lastFrame = time;
    }
};