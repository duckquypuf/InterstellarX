#pragma once

#include <string>

#include "window.h"
#include "input.h"
#include "renderer.h"

#include "mesh.h"
#include "mesh_primitives.h"

#include "scene.h"

namespace InterstellarX {
    class Application
    {
    public:
        static Window *window;
        static InterstellarX::Input *input;
        static InterstellarX::Renderer *renderer;
        static InterstellarX::Scene *scene;

        static void InitWindow(int width, int height, std::string name) {
            window = new Window(name, width, height);
            input = new InterstellarX::Input();
            renderer = new InterstellarX::Renderer();
            Primitives::Init();
            scene = new InterstellarX::Scene();
            scene->init();
        }

        static void Start() {
            scene->start();
        }

        static void Update() {
            input->update(window->window);
            scene->update();
            renderer->beginFrame();
            renderer->render(scene, window);
            window->update();
        }

        static bool isRunning() {
            return !glfwWindowShouldClose(window->window);
        }
    };
};