#pragma once

#include <glad/glad.h>

#include "mesh.h"
#include "scene.h"

namespace InterstellarX {
    class Renderer
    {
    public:
        glm::mat4 projection;

        Renderer() {
            projection = glm::perspective(
                glm::radians(45.0f), // FOV
                1280.0f / 720.0f,    // Aspect ratio
                0.1f,                // Near plane
                100.0f               // Far plane
            );

            // Enable depth testing
            glEnable(GL_DEPTH_TEST);
        }

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
                e->shader->setMat4("view", scene->camera->GetViewMatrix());
                e->shader->setMat4("projection", projection);
                e->mesh->Draw();
            }
        }
    };
}