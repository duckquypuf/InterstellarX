#pragma once

#include <vector>

#include "transform.h"
#include "mesh.h"
#include "component.h"

namespace InterstellarX {
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
    };

    inline Entity *Instantiate(Mesh *primitive) {
        // Primitive
        Entity *e = new Entity();
        e->mesh = primitive;

        return e;
    }

    inline Entity *Instantiate(Entity *prefab, Transform &transform) {
        // Prefabs
        Entity *e = new Entity();
        e->transform = Transform(transform.position, transform.rotation, transform.scale);
        e->mesh = prefab->mesh;

        return e;
    }

    inline Entity *Instantiate() {
        // Empty Gameobject
        return new Entity();
    }
}