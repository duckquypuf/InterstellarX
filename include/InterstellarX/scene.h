#pragma once

#include <vector>

#include "Components/camera.h"
#include "entity.h"

namespace InterstellarX {
    class Scene {
    public:
        std::vector<InterstellarX::Entity*> entities;

        Entity *cameraObject;
        Camera *camera;

        ~Scene() {
            for (auto e : entities)
                delete e;
            entities.clear();
        }

        void init() {
            cameraObject = new Entity();
            camera = cameraObject->addComponent<Camera>();
            entities.push_back(cameraObject);
        }

        void add(Entity *e) {
            entities.push_back(e);
        }

        void start() {
            for (auto &e : entities) {
                for(auto &c : e->components) {
                    c->Start();
                }
            }
        }

        void update() {
            for(auto &e : entities) {
                for (auto &c : e->components) {
                    c->Update();
                }
            }
        }
    };
}