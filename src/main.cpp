#include <iostream>

#include "application.h"

int main()
{
    Application::Init();

    InterstellarX::Primitives::InitCube();

    // Create a shader
    InterstellarX::Shader *basicShader = new InterstellarX::Shader(
        "basic_vert.glsl",
        "basic_frag.glsl");

    // Create an entity with the cube
    InterstellarX::Entity *cube = new InterstellarX::Entity();
    cube->mesh = InterstellarX::Primitives::Cube;
    cube->shader = basicShader;
    cube->transform.position = glm::vec3(0.0f, 0.0f, 0.0f);

    // Add it to the scene
    Application::scene->add(cube);

    // Make it spin!
    while (!glfwWindowShouldClose(Application::window->window))
    {
        // Rotate the cube
        cube->transform.rotation.y += 50.0f * InterstellarX::Time::deltaTime;
        cube->transform.rotation.x += 30.0f * InterstellarX::Time::deltaTime;

        Application::renderer->beginFrame(); // Don't forget this!
        Application::Update();
    }

    return 0;
}