#include "camera.h"
#include "InterstellarX/entity.h"

using namespace InterstellarX;

glm::mat4 Camera::GetViewMatrix()
{
    // Convert rotation to direction vectors
    glm::vec3 forward = GetForwardVector();
    glm::vec3 up = GetUpVector();

    // Look at: position + forward direction
    return glm::lookAt(
        entity->transform.position,
        entity->transform.position + forward,
        up);
}

glm::vec3 Camera::GetForwardVector()
{
    glm::vec3 forward;
    forward.x = cos(glm::radians(entity->transform.rotation.y)) * cos(glm::radians(entity->transform.rotation.x));
    forward.y = sin(glm::radians(entity->transform.rotation.x));
    forward.z = sin(glm::radians(entity->transform.rotation.y)) * cos(glm::radians(entity->transform.rotation.x));
    return glm::normalize(forward);
}