#pragma once

#include "mesh.h"

namespace InterstellarX::Primitives {
    inline static Mesh* Cube = nullptr;
    inline static Mesh *Plane = nullptr;

    inline void InitCube() {
        std::vector<float> vertices = {
            // positions         // normals       // uvs
            // Front face
            -0.5f, -0.5f, 0.5f, 0, 0, 1, 0, 0,
            0.5f, -0.5f, 0.5f, 0, 0, 1, 1, 0,
            0.5f, 0.5f, 0.5f, 0, 0, 1, 1, 1,
            -0.5f, 0.5f, 0.5f, 0, 0, 1, 0, 1,
            // Back face
            -0.5f, -0.5f, -0.5f, 0, 0, -1, 0, 0,
            0.5f, -0.5f, -0.5f, 0, 0, -1, 1, 0,
            0.5f, 0.5f, -0.5f, 0, 0, -1, 1, 1,
            -0.5f, 0.5f, -0.5f, 0, 0, -1, 0, 1,
            // Left face
            -0.5f, -0.5f, -0.5f, -1, 0, 0, 0, 0,
            -0.5f, 0.5f, -0.5f, -1, 0, 0, 1, 0,
            -0.5f, 0.5f, 0.5f, -1, 0, 0, 1, 1,
            -0.5f, -0.5f, 0.5f, -1, 0, 0, 0, 1,
            // Right face
            0.5f, -0.5f, -0.5f, 1, 0, 0, 0, 0,
            0.5f, 0.5f, -0.5f, 1, 0, 0, 1, 0,
            0.5f, 0.5f, 0.5f, 1, 0, 0, 1, 1,
            0.5f, -0.5f, 0.5f, 1, 0, 0, 0, 1,
            // Top face
            -0.5f, 0.5f, -0.5f, 0, 1, 0, 0, 0,
            0.5f, 0.5f, -0.5f, 0, 1, 0, 1, 0,
            0.5f, 0.5f, 0.5f, 0, 1, 0, 1, 1,
            -0.5f, 0.5f, 0.5f, 0, 1, 0, 0, 1,
            // Bottom face
            -0.5f, -0.5f, -0.5f, 0, -1, 0, 0, 0,
            0.5f, -0.5f, -0.5f, 0, -1, 0, 1, 0,
            0.5f, -0.5f, 0.5f, 0, -1, 0, 1, 1,
            -0.5f, -0.5f, 0.5f, 0, -1, 0, 0, 1};

        std::vector<unsigned int> indices = {
            // Front
            2, 1, 0, 0, 3, 2,
            // Back
            4, 5, 6, 6, 7, 4,
            // Left
            8, 9, 10, 10, 11, 8,
            // Right
            14, 13, 12, 12, 15, 14,
            // Top
            16, 17, 18, 18, 19, 16,
            // Bottom
            22, 21, 20, 20, 23, 22};

        Cube = new Mesh(vertices, indices);
    }

    inline void InitPlane()
    {
        std::vector<float> vertices = {
            // positions          // normals      // uvs
            -10.0f, 0.0f, -10.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            10.0f, 0.0f, -10.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
            10.0f, 0.0f, 10.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
            -10.0f, 0.0f, 10.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};

        std::vector<unsigned int> indices = {0, 1, 2, 2, 3, 0};
        Plane = new Mesh(vertices, indices);
    }
}