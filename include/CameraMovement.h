#pragma once

#include "InterstellarX/InterstellarX.h"

using namespace InterstellarX;

class CameraMovement : public Component {
public:
    void Update() override {
        if(Application::input->isKeyDown(Application::window->window, Keys::KEY_SPACE)) {
            entity->transform.position.y += 2.0f * Time::deltaTime;
        }
    }
};