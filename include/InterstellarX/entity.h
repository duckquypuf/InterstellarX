#pragma once

#include <vector>

#include "Components/transform.h"
#include "mesh.h"
#include "Components/component.h"

namespace InterstellarX {
    class Application;
    class Scene;

    class Entity {
    public:
        InterstellarX::Transform transform;
        InterstellarX::Mesh *mesh;

        std::vector<std::unique_ptr<Component>> components;

        template <typename T>
        T *getComponent() {
            for (auto &component : components) {
                T *target = dynamic_cast<T *>(component.get());

                if (target)
                    return target;
            }
            return nullptr;
        }

        template <typename T, typename... Args>
        T *addComponent(Args &&...args)
        {
            auto newComp = std::make_unique<T>(std::forward<Args>(args)...);
            T *ptr = newComp.get();
            newComp->SetEntity(this);
            components.push_back(std::move(newComp));
            return ptr;
        }
    };

    Entity *Instantiate(Mesh *primitive);
    Entity *Instantiate(Entity *prefab, Transform &transform);
    Entity *Instantiate();
}