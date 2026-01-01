#pragma once

#include <glad/glad.h>

#include "mesh.h"
#include "scene.h"

namespace InterstellarX {
    class Renderer
    {
    public:
        Renderer() {
            // Enable depth testing
            glEnable(GL_DEPTH_TEST);

            glFrontFace(GL_CW);
            glCullFace(GL_BACK);
            glEnable(GL_CULL_FACE);
        }

        void beginFrame()
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void render(Scene *scene, Window *window) {
            for(auto &e : scene->entities)
            {
                if(e->mesh) {
                    e->mesh->material.shader->use();
                    e->mesh->material.shader->setMat4("model", e->transform.GetTransformationMatrix());
                    e->mesh->material.shader->setMat4("view", scene->camera->GetViewMatrix());
                    e->mesh->material.shader->setMat4("projection", scene->camera->GetProjectionMatrix(window));
                    e->mesh->Draw();
                }
            }
        }
    };
}