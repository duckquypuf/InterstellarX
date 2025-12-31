#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace InterstellarX {
    class Transform {
    public:
        glm::vec3 position = glm::vec3(0.0f);
        glm::vec3 rotation;
        glm::vec3 scale = glm::vec3(1.0f);

        glm::mat4 GetTransformationMatrix() {
            glm::mat4 transform = glm::mat4(1.0f);

            transform = glm::translate(transform, position);
            transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1, 0, 0));
            transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0, 1, 0));
            transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0, 0, 1));
            transform = glm::scale(transform, scale);

            return transform;
        }
    };
}