#pragma once

namespace InterstellarX {
    class Entity;

    class Component {
    protected:
        Entity *entity;
    public:
        virtual ~Component() = default;

        void SetEntity(Entity *obj) { entity = obj; }
    };
};