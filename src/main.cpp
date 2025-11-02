#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdint>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

const std::string TITLE{"Mazeophobia"};
const uint32_t WIDTH{1200};
const uint32_t HEIGHT{800};

int main(void) {
    // GLFW handle
    if (glfwInit() == GLFW_FALSE) {
        std::cerr << "RUNTIME ERR: Failed to create GLFW handle\n";
        return EXIT_FAILURE;
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // not using OpenGL
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    // GLFW window
    constexpr auto WINDOWED_MODE        = nullptr;
    constexpr auto DONT_SHARE_RESOURCES = nullptr;
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITLE.c_str(), WINDOWED_MODE, DONT_SHARE_RESOURCES);

    if (window == nullptr) {
        glfwTerminate();
        std::cerr << "RUNTIME ERR: Failed to create GLFW window\n";
        return EXIT_FAILURE;
    }

    // Vk Application Info
    VkApplicationInfo appInfo{
        VK_STRUCTURE_TYPE_APPLICATION_INFO,
        nullptr,
        "Triangle",
        VK_MAKE_VERSION(1, 0, 0),
        "No Engine",
        VK_MAKE_VERSION(1, 0, 0),
        VK_API_VERSION_1_0
    };

    uint32_t glfwExtensionCount{0};
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    // Pass AppInfo to Vk handle
    VkInstanceCreateInfo createInfo{
        VK_STRUCTURE_TYPE_APPLICATION_INFO,          
        nullptr,
        0,
        &appInfo,
        0,
        nullptr,
        glfwExtensionCount,
        glfwExtensions,
    };

    // Create Vk handle
    VkInstance instance;
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        std::cerr << "RUNTIME ERR: Failed to create VkInstance\n";
        return EXIT_FAILURE;
    }

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    // Clean up
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}
