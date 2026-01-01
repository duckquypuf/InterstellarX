#pragma once

#include <glm/glm.hpp>

#include "component.h"

namespace InterstellarX
{
    class Rigidbody : public Component
    {
    public:
        glm::vec3 velocity = glm::vec3(0.0f);
        bool useGravity = true;
        float gravity = 9.81f;
        //TODO: bool doCollisions = true;

        void Start() override {

        }

        void Update() override {
            velocity.y -= gravity * Time::deltaTime;
            entity->transform.position += velocity * Time::deltaTime;
        }
    };
}