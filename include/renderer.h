#pragma once

#include <glad/glad.h>

#include "mesh.h"
#include "scene.h"

namespace InterstellarX {
    class Renderer
    {
    public:
        void beginFrame()
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }

        void render(InterstellarX::Scene *scene) {
            for(auto &e : scene->entities)
            {
                e->shader->use();
                e->shader->setMat4("model", e->transform.GetTransformationMatrix());
                e->mesh->Draw();
            }
        }
    };
}