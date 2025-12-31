#pragma once

#include <vector>

#include "entity.h"

namespace InterstellarX {
    class Scene {
    public:
        std::vector<InterstellarX::Entity*> entities;

        void add(Entity *e) {
            entities.push_back(e);
        }
    };
}