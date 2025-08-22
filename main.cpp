#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main() {
    // 初始化 GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // 设置 OpenGL 版本（比如 3.3 Core Profile）
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 800, "Jeck leanrn opengl", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // 绑定 OpenGL 上下文
    glfwMakeContextCurrent(window);

    // 初始化 GLAD (GLAD 2)
    if (!gladLoaderLoadGL()) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 400, 400);

    // 打印 OpenGL 版本，验证 GLAD 是否成功加载
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    // 主循环
    while (!glfwWindowShouldClose(window)) {

        processInput(window);
        // 设置背景色
        glEnable(GL_SCISSOR_TEST);
        glScissor(0, 0, 400, 400);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDisable(GL_SCISSOR_TEST);

        // 交换缓冲区 & 处理事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


