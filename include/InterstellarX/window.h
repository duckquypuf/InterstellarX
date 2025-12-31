#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <sstream>
#include <iomanip>

#include "InterstellarX/interstellar_time.h"
#include "InterstellarX/input.h"

namespace InterstellarX {
    class Window
    {
    public:
        int screenWidth, screenHeight;
        GLFWwindow *window;
        std::string windowName;

        Window(std::string windowName, int screenWidth, int screenHeight)
        {
            this->screenWidth = screenWidth;
            this->screenHeight = screenHeight;
            this->windowName = windowName;
            initOpenGL();
        }

        void initOpenGL()
        {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            window = glfwCreateWindow(screenWidth, screenHeight, windowName.c_str(), NULL, NULL);

            if (window == NULL)
            {
                glfwTerminate();
                return;
            }

            glfwMakeContextCurrent(window);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                glfwTerminate();
                return;
            }
        }

        void update()
        {
            // --- Calculate Time ---
            InterstellarX::Time::Update();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

    private:
        double lastX = 0.0, lastY = 0.0;
        bool firstMouse = true;
    };
};