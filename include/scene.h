#pragma once

#include <vector>

#include "camera.h"
#include "entity.h"

namespace InterstellarX {
    class Scene {
    public:
        std::vector<InterstellarX::Entity*> entities;

        Camera *camera;

        void init() {
            camera = new Camera();
        }

        void add(Entity *e) {
            entities.push_back(e);
        }
    };
}