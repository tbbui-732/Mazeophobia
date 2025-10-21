#include <iostream>
#include <stdexcept>
#include <cstdlib>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

struct Application {
    GLFWwindow* window;

    void run() {
        init_glfw();
        init_vulkan();
        loop();
        cleanup();
    }

    void init_glfw() {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // not using opengl
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window = glfwCreateWindow(WIDTH, HEIGHT, "Mazeophobia - Vulkan Window", nullptr, nullptr);
    }

    void init_vulkan() {}

    void loop() {}

    void cleanup() {}
};

int main() {
    Application app;
    // TODO: avoid try-catch; use std::optional instead
    // NOTE: what's the difference between std::optional and std::expected?
    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
