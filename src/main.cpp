#include <iostream>

#include "application.h"

void UpdateCamera()
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
    if (true)//input.rightMouseButton)
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

int main()
{
    Application::Init();

    InterstellarX::Primitives::InitCube();
    InterstellarX::Primitives::InitPlane();

    InterstellarX::Shader *basicShader = new InterstellarX::Shader("basic_vert.glsl", "basic_frag.glsl");

    InterstellarX::Entity *cube = new InterstellarX::Entity();
    cube->mesh = InterstellarX::Primitives::Cube;
    cube->shader = basicShader;
    cube->transform.position = glm::vec3(0.0f, 0.0f, 0.0f);

    InterstellarX::Entity *ground = new InterstellarX::Entity();
    ground->mesh = InterstellarX::Primitives::Plane;
    ground->shader = basicShader;
    ground->transform.position = glm::vec3(0.0f, -2.0f, 0.0f);

    Application::scene->add(ground);
    Application::scene->add(cube);

    while (!glfwWindowShouldClose(Application::window->window))
    {
        UpdateCamera();
        Application::Update();
    }

    return 0;
}