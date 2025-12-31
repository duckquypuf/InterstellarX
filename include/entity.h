#pragma once

#include "transform.h"
#include "mesh.h"

namespace InterstellarX {
    class Entity {
    public:
        InterstellarX::Transform transform;
        InterstellarX::Mesh *mesh;
    };
}