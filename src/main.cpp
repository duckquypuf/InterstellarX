#include <iostream>

#include "InterstellarX.h"

int main()
{
    Application::Init();

    InterstellarX::Primitives::InitCube();
    InterstellarX::Primitives::InitPlane();

    InterstellarX::Shader *basicShader = new InterstellarX::Shader("basic_vert.glsl", "basic_frag.glsl");

    InterstellarX::Entity *cube = new InterstellarX::Entity();
    cube->mesh = InterstellarX::Primitives::Cube;
    cube->mesh->material.shader = basicShader;
    cube->transform.position = glm::vec3(0.0f, 0.0f, 0.0f);

    InterstellarX::Entity *ground = new InterstellarX::Entity();
    ground->mesh = InterstellarX::Primitives::Plane;
    ground->mesh->material.shader = basicShader;
    ground->transform.position = glm::vec3(0.0f, -2.0f, 0.0f);

    Application::scene->add(ground);
    Application::scene->add(cube);

    while (!glfwWindowShouldClose(Application::window->window))
    {
        Application::Update();
    }

    return 0;
}