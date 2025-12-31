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
        window = new Window("InterstellarX", 1440, 900);
        input = new InterstellarX::Input();
        renderer = new InterstellarX::Renderer();
        scene = new InterstellarX::Scene();
        scene->init();
    }

    static void Update()
    {
        UpdateCamera();
        input->update(window->window);
        renderer->beginFrame();
        renderer->render(scene);
        window->update();
    }

private:
    static void UpdateCamera()
    {
        float speed = 5.0f * InterstellarX::Time::deltaTime;
        float sensitivity = 0.2f;

        auto cam = Application::scene->camera;
        auto input = Application::input->state;

        // WASD movement
        if (input.w)
            cam->transform.position += cam->GetForwardVector() * speed;
        if (input.s)
            cam->transform.position -= cam->GetForwardVector() * speed;
        if (input.a)
            cam->transform.position -= cam->GetRightVector() * speed;
        if (input.d)
            cam->transform.position += cam->GetRightVector() * speed;

        // Mouse look (when right mouse button is held)
        if (true) // input.rightMouseButton)
        {
            cam->transform.rotation.y += input.mouseX * sensitivity;
            cam->transform.rotation.x += input.mouseY * sensitivity;

            // Clamp pitch to prevent flipping
            if (cam->transform.rotation.x > 89.0f)
                cam->transform.rotation.x = 89.0f;
            if (cam->transform.rotation.x < -89.0f)
                cam->transform.rotation.x = -89.0f;
        }
    }
};