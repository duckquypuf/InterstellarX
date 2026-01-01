#pragma once

#include <vector>

#include "Components/camera.h"
#include "entity.h"
#include "Components/monobehaviour.h"

namespace InterstellarX {
    class Scene {
    public:
        std::vector<InterstellarX::Entity*> entities;

        Entity *cameraObject;
        Camera *camera;

        void init() {
            cameraObject = new Entity();
            camera = cameraObject->addComponent<Camera>();
        }

        void add(Entity *e) {
            entities.push_back(e);
        }

        void start() {
            camera->Start();

            for (auto &e : entities) {
                for(auto &c : e->components) {
                    c->Start();
                }
            }
        }

        void update() {
            camera->Update();

            for(auto &e : entities) {
                for (auto &c : e->components) {
                    c->Update();
                }
            }
        }
    };
}