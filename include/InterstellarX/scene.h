#pragma once

#include <vector>

#include "camera.h"
#include "entity.h"
#include "monobehaviour.h"

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

        void start() {
            for (auto &e : entities) {
                MonoBehaviour *script = e->getComponent<MonoBehaviour>();
                if (script) {
                    script->Start();
                }
            }
        }

        void update() {
            for(auto &e : entities) {
                MonoBehaviour *script = e->getComponent<MonoBehaviour>();
                if(script) {
                    script->Update();
                }
            }
        }
    };
}