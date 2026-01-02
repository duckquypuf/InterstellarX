#pragma once

#include "InterstellarX/InterstellarX.h"

using namespace InterstellarX;

class CameraMovement : public Component {
public:
    void Update() override {
        auto cam = entity->getComponent<Camera>();
        glm::vec3 move = Input::getMoveDirection();

        float speed = 3.0f;
        float sensitivity = 0.2f;

        // Movement
        entity->transform.position += cam->GetForwardVector() * move.z * speed * Time::deltaTime;
        entity->transform.position += cam->GetRightVector() * move.x * speed * Time::deltaTime;
        entity->transform.position.y += move.y * speed * Time::deltaTime;

        // Mouse look
        if (true)
        {
            glm::vec2 mouseDelta = Input::getMouseDelta();
            entity->transform.rotation.y += mouseDelta.x * sensitivity;
            entity->transform.rotation.x -= mouseDelta.y * sensitivity;
            entity->transform.rotation.x = glm::clamp(entity->transform.rotation.x, -89.0f, 89.0f);
        }
    }
};