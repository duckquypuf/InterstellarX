#pragma once

#include <GLFW/glfw3.h>

namespace InterstellarX {
    namespace Keys
    {
        static constexpr int KEY_SPACE = GLFW_KEY_SPACE;
        static constexpr int KEY_ENTER = GLFW_KEY_ENTER;
        static constexpr int KEY_ESCAPE = GLFW_KEY_ESCAPE;
        static constexpr int KEY_BACKSPACE = GLFW_KEY_BACKSPACE;
        static constexpr int KEY_DELETE = GLFW_KEY_DELETE;
        static constexpr int KEY_TAB = GLFW_KEY_TAB;

        // Arrows
        static constexpr int KEY_UP = GLFW_KEY_UP;
        static constexpr int KEY_DOWN = GLFW_KEY_DOWN;
        static constexpr int KEY_LEFT = GLFW_KEY_LEFT;
        static constexpr int KEY_RIGHT = GLFW_KEY_RIGHT;

        // Function Keys
        static constexpr int KEY_F1 = GLFW_KEY_F1;
        static constexpr int KEY_F2 = GLFW_KEY_F2;
        static constexpr int KEY_F3 = GLFW_KEY_F3;
        static constexpr int KEY_F4 = GLFW_KEY_F4;
        static constexpr int KEY_F5 = GLFW_KEY_F5;
        static constexpr int KEY_F6 = GLFW_KEY_F6;
        static constexpr int KEY_F7 = GLFW_KEY_F7;
        static constexpr int KEY_F8 = GLFW_KEY_F8;
        static constexpr int KEY_F9 = GLFW_KEY_F9;
        static constexpr int KEY_F10 = GLFW_KEY_F10;
        static constexpr int KEY_F11 = GLFW_KEY_F11;
        static constexpr int KEY_F12 = GLFW_KEY_F12;

        // Control Keys (Common for games)
        static constexpr int KEY_W = GLFW_KEY_W;
        static constexpr int KEY_A = GLFW_KEY_A;
        static constexpr int KEY_S = GLFW_KEY_S;
        static constexpr int KEY_D = GLFW_KEY_D;
        static constexpr int KEY_Q = GLFW_KEY_Q;
        static constexpr int KEY_E = GLFW_KEY_E;
        static constexpr int KEY_R = GLFW_KEY_R;
        static constexpr int KEY_F = GLFW_KEY_F;
        static constexpr int KEY_SHIFT = GLFW_KEY_LEFT_SHIFT;
        static constexpr int KEY_CTRL = GLFW_KEY_LEFT_CONTROL;
    }

    struct InputState
    {
        bool leftMouseButton = false;
        bool rightMouseButton = false;

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

        bool isKeyDown(GLFWwindow *window, int key){
            return glfwGetKey(window, key) == GLFW_PRESS;
        }

        glm::vec2 getMousePos(GLFWwindow *window)
        {
            double x, y;
            glfwGetCursorPos(window, &x, &y);
            return {float(x), float(y)};
        }
    };
};