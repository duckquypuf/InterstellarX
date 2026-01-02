#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "keys.h"

namespace InterstellarX {
    class Input {
    private:
        inline static glm::vec2 mouseDelta = glm::vec2(0.0f);
        inline static glm::vec2 prevMousePos = glm::vec2(0.0f);
        inline static bool firstMouseUpdate = true;

    public:
        // Keyboard
        static bool isKeyDown(int key);

        static bool isKeyUp(int key) {
            return !isKeyDown(key);
        }

        static glm::vec3 getMoveDirection() {
            glm::vec3 dir = glm::vec3(0.0f);

            dir.x += isKeyDown(Keys::KEY_D) ? 1.0f : 0.0f;
            dir.x -= isKeyDown(Keys::KEY_A) ? 1.0f : 0.0f;

            dir.z += isKeyDown(Keys::KEY_W) ? 1.0f : 0.0f;
            dir.z -= isKeyDown(Keys::KEY_S) ? 1.0f : 0.0f;

            dir.y += isKeyDown(Keys::KEY_SPACE) ? 1.0f : 0.0f;
            dir.y -= isKeyDown(Keys::KEY_LEFT_SHIFT) ? 1.0f : 0.0f;

            return dir;
        }

        // Mouse Buttons
        bool isMouseButtonDown(int button);

        bool getLeftMouseButton();

        bool getRightMouseButton();

        // Mouse Movement
        static glm::vec2 getMousePosition();

        static float getMouseX() {
            return getMousePosition().x;
        }

        static float getMouseY() {
            return getMousePosition().y;
        }

        static glm::vec2 getMouseDelta() {
            return mouseDelta;
        }

        static void update() {
            glm::vec2 currentPos = getMousePosition();

            if (firstMouseUpdate) {
                prevMousePos = currentPos;
                firstMouseUpdate = false;
            }

            mouseDelta = currentPos - prevMousePos;
            prevMousePos = currentPos;
        }
    };
};