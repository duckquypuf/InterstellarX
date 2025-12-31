#include <iostream>

#include "InterstellarX/InterstellarX.h"

using namespace InterstellarX;

int main()
{
    Application::Init();

    Primitives::InitCube();
    Primitives::InitPlane();

    Shader *basicShader = new Shader("basic_vert.glsl", "basic_frag.glsl");

    Entity *cube = Instantiate(Primitives::Cube);
    cube->mesh->material.shader = basicShader;

    Entity *ground = Instantiate(Primitives::Plane);
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