#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "InterstellarX/window.h"
#include "transform.h"
#include "component.h"

namespace InterstellarX {
    class Camera : public Component {
    public:
        float fov = 45.0f;

        glm::mat4 GetViewMatrix();

        glm::mat4 GetProjectionMatrix(Window *window)
        {
            glm::mat4 projection = glm::perspective(
                glm::radians(fov), // FOV
                (float)window->screenWidth / (float)window->screenHeight,    // Aspect ratio
                0.1f,                // Near plane
                100.0f               // Far plane
            );

            return projection;
        }

        glm::vec3 GetForwardVector();

        glm::vec3 GetRightVector()
        {
            return glm::normalize(glm::cross(GetForwardVector(), glm::vec3(0.0f, 1.0f, 0.0f)));
        }

        glm::vec3 GetUpVector()
        {
            return glm::normalize(glm::cross(GetRightVector(), GetForwardVector()));
        }
    };
};