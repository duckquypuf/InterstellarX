#pragma once

#include "window.h"
#include "input.h"
#include "renderer.h"

#include "mesh.h"
#include "mesh_primitives.h"

#include "scene.h"

class Application
{
public:
    static Window *window;
    static InterstellarX::Input *input;
    static InterstellarX::Renderer *renderer;
    static InterstellarX::Scene *scene;

    static void Init()
    {
        window = new Window("InterstellarX", 1280, 720);
        input = new InterstellarX::Input();
        renderer = new InterstellarX::Renderer();
        scene = new InterstellarX::Scene();
    }

    static void Update()
    {
        input->update(window->window);
        renderer->render(scene);
        window->update();
    }
};