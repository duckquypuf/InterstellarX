# InterstellarX

InterstellarX is a C++ game engine created by **duckquypuf**, built on top of OpenGL. It is currently in early development — production started on 31.12.25.

## Features

- **Entity-Component System** — attach and retrieve components on any entity via `addComponent<T>()` / `getComponent<T>()`
- **Transform** — position, rotation, and scale with matrix generation for rendering
- **Camera** — perspective projection, forward/right/up vector calculation, and view matrix
- **Rigidbody** — gravity and velocity-based physics simulation
- **Input** — keyboard and mouse input via GLFW, including `getMoveDirection()` and mouse delta tracking
- **Mesh & Primitives** — built-in cube and plane meshes with VAO/VBO/EBO management
- **Shader** — GLSL vertex and fragment shader loading, compilation, and uniform setters
- **Renderer** — depth testing, back-face culling, and per-entity draw calls
- **Scene** — manages entities, the camera object, and calls `Start()` / `Update()` on all components
- **Asset Loading** — texture loading via `stb_image` with mipmap and format detection
- **Time** — `deltaTime` and total elapsed time via `InterstellarX::Time`
- **Window** — GLFW/GLAD window creation and OpenGL context management

## Getting Started

### Prerequisites

- CMake
- A C++17-compatible compiler
- OpenGL 4.1+
- GLFW, GLAD, GLM, stb_image (included or linked via your build system)

### Building

```bash
mkdir build && cd build
cmake ..
make
```

### Running

```bash
./InterstellarX
```

Assets (shaders, textures) are expected at `../assets/` relative to the binary.

## Project Structure

```
InterstellarX/
├── include/
│   ├── InterstellarX/
│   │   ├── Components/
│   │   │   ├── camera.h / camera.cpp
│   │   │   ├── component.h
│   │   │   ├── rigidbody.h
│   │   │   └── transform.h
│   │   ├── application.h / application.cpp
│   │   ├── assets.h
│   │   ├── entity.h / entity.cpp
│   │   ├── input_helper.h / input_helper.cpp
│   │   ├── interstellar_time.h
│   │   ├── keys.h
│   │   ├── material.h
│   │   ├── mesh.h
│   │   ├── mesh_primitives.h
│   │   ├── renderer.h
│   │   ├── scene.h
│   │   ├── shader.h
│   │   └── window.h
│   └── CameraMovement.h
├── src/
│   ├── main.cpp
│   └── stb_impl.cpp
└── assets/
    ├── shaders/
    └── texture/
```

## Usage Example

```cpp
#include "InterstellarX/InterstellarX.h"
#include "CameraMovement.h"

using namespace InterstellarX;

int main() {
    Application::InitWindow(1440, 900, "My Game");

    Shader *basicShader = new Shader("basic_vert.glsl", "basic_frag.glsl");

    Entity *cube = Instantiate(Primitives::Cube);
    cube->mesh->material.shader = basicShader;
    cube->addComponent<Rigidbody>();

    Entity *ground = Instantiate(Primitives::Plane);
    ground->mesh->material.shader = basicShader;
    ground->transform.position = glm::vec3(0.0f, -2.0f, 0.0f);

    Application::scene->cameraObject->addComponent<CameraMovement>();

    Application::Start();
    while (Application::isRunning()) {
        Application::Update();
    }
}
```

## Roadmap

- [x] Entity-Component System
- [x] Camera with mouse look
- [x] Rigidbody with gravity
- [x] Mesh primitives (Cube, Plane)
- [x] Shader system
- [x] Texture loading
- [ ] Collision detection
- [ ] Scene serialization / prefab system
- [ ] Lighting (directional, point)
- [ ] Material system (textures, colours)
- [ ] Physics improvements (drag, mass, constraints)

## License

This project is currently unlicensed and in personal development.
