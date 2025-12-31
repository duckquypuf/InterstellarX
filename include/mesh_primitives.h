#pragma once

#include "mesh.h"

namespace InterstellarX::Primitives {
    inline static Mesh* Cube = nullptr;

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
            0, 1, 2, 2, 3, 0,
            // Back
            4, 5, 6, 6, 7, 4,
            // Left
            8, 9, 10, 10, 11, 8,
            // Right
            12, 13, 14, 14, 15, 12,
            // Top
            16, 17, 18, 18, 19, 16,
            // Bottom
            20, 21, 22, 22, 23, 20};

        Cube = new Mesh(vertices, indices);
    }
}