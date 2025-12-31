#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "transform.h"

namespace InterstellarX {
    class Camera {
    public:
        Transform transform;

        glm::mat4 GetViewMatrix()
        {
            // Convert rotation to direction vectors
            glm::vec3 forward = GetForwardVector();
            glm::vec3 up = GetUpVector();

            // Look at: position + forward direction
            return glm::lookAt(
                transform.position,
                transform.position + forward,
                up);
        }

        glm::vec3 GetForwardVector()
        {
            glm::vec3 forward;
            forward.x = cos(glm::radians(transform.rotation.y)) * cos(glm::radians(transform.rotation.x));
            forward.y = sin(glm::radians(transform.rotation.x));
            forward.z = sin(glm::radians(transform.rotation.y)) * cos(glm::radians(transform.rotation.x));
            return glm::normalize(forward);
        }

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