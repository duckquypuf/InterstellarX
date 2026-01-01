#include <iostream>

#include "InterstellarX/InterstellarX.h"
#include "CameraMovement.h"

using namespace InterstellarX;

int main()
{
    Application::InitWindow(1440, 900, "InterstellarX Window");

    Shader *basicShader = new Shader("basic_vert.glsl", "basic_frag.glsl");

    Entity *cube = Instantiate(Primitives::Cube);
    cube->mesh->material.shader = basicShader;

    cube->addComponent<Rigidbody>();

    Entity *ground = Instantiate(Primitives::Plane);
    ground->mesh->material.shader = basicShader;
    ground->transform.position = glm::vec3(0.0f, -2.0f, 0.0f);

    Application::scene->cameraObject->addComponent<CameraMovement>();

    Application::Start();
    while (!glfwWindowShouldClose(Application::window->window))
    {
        Application::Update();
    }

    return 0;
}