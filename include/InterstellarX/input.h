#pragma once

#include <GLFW/glfw3.h>

namespace InterstellarX {
    struct InputState
    {
        bool leftMouseButton = false;
        bool rightMouseButton = false;

        bool w = false;
        bool a = false;
        bool s = false;
        bool d = false;
        bool spacebar = false;

        float mouseX = 0.0f;
        float mouseY = 0.0f;
    };

    class Input
    {
    public:
        InputState state{};
        double lastX = 0.0, lastY = 0.0;
        bool firstMouse = true;

        void update(GLFWwindow *window)
        {
            state.w = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
            state.a = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
            state.s = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
            state.d = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
            state.spacebar = glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS;

            double x, y;
            glfwGetCursorPos(window, &x, &y);
            if (firstMouse)
            {
                lastX = x;
                lastY = y;
                firstMouse = false;
            }

            state.mouseX = float(x - lastX);
            state.mouseY = float(lastY - y);
            lastX = x;
            lastY = y;

            state.leftMouseButton = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
            state.rightMouseButton = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
        }

        glm::vec2 getMousePos(GLFWwindow *window)
        {
            double x, y;
            glfwGetCursorPos(window, &x, &y);
            return {float(x), float(y)};
        }
    };
};