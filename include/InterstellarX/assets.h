#pragma once

#include <glad/glad.h>

#include <filesystem>
#include <iostream>
#include <string>

#include <stb_image.h>

namespace Assets {
    class Texture {
    public:
        std::string filePath;
        uint id;

        Texture(std::string path) {
            filePath = path;
            id = loadTexture(("../assets/texture/" + path).c_str());
        }
    };

    inline unsigned int loadTexture(const char *path)
    {
        if (!std::filesystem::exists(path))
        {
            std::cout << "ERROR: File does not exist at path: " << path << std::endl;
            return 0;
        }

        unsigned int id;
        glGenTextures(1, &id);

        int width, height, nrComponents;
        unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);

        if (data)
        {
            GLenum format;

            if (nrComponents == 1)
                format = GL_RED;
            else if (nrComponents == 3)
                format = GL_RGB;
            else if (nrComponents == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, id);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            stbi_image_free(data);
        }
        else
        {
            std::cout << "STB Image failed to load. Reason: " << stbi_failure_reason() << std::endl;
            std::cout << "Path attempted: " << path << std::endl;
            stbi_image_free(data);
            return 0;
        }
        return id;
    }
};