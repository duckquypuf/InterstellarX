#pragma once

namespace InterstellarX {
    class Entity;

    class Component {
    protected:
        Entity *entity;
    public:
        virtual ~Component() = default;

        virtual void Start() {}
        virtual void Update() {}

        void SetEntity(Entity *obj) { entity = obj; }
    };
};