#pragma once

#include "transform.h"
#include "shader.h"
#include "mesh.h"

namespace InterstellarX {
    class Entity {
    public:
        InterstellarX::Transform transform;
        InterstellarX::Shader *shader;
        InterstellarX::Mesh *mesh;
    };
}