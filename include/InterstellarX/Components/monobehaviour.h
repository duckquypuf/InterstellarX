#pragma once

#include "component.h"

namespace InterstellarX {
    class MonoBehaviour : public Component {
    public:
        virtual void Start() {}
        virtual void Update() {}
    };
}