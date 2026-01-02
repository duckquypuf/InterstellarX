#include "application.h"
#include "input_helper.h"

namespace InterstellarX {
    bool Input::isKeyDown(int key) {
        return glfwGetKey(Application::window->window, key) == GLFW_PRESS;
    }

    bool Input::isMouseButtonDown(int button) {
        if (button == 0)
            return glfwGetMouseButton(Application::window->window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
        if (button == 1)
            return glfwGetMouseButton(Application::window->window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
        return false;
    }

    bool Input::getLeftMouseButton() {
        return glfwGetMouseButton(Application::window->window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
    }

    bool Input::getRightMouseButton() {
        return glfwGetMouseButton(Application::window->window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
    }

    glm::vec2 Input::getMousePosition() {
        double x, y;
        glfwGetCursorPos(Application::window->window, &x, &y);
        return glm::vec2(x, y);
    }
};