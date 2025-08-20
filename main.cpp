#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // ��ʼ�� GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // ���� OpenGL �汾������ 3.3 Core Profile��
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // ��������
    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW + GLAD Test", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // �� OpenGL ������
    glfwMakeContextCurrent(window);

    // ��ʼ�� GLAD (GLAD 2)
    if (!gladLoaderLoadGL()) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }



    // ��ӡ OpenGL �汾����֤ GLAD �Ƿ�ɹ�����
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    // ��ѭ��
    while (!glfwWindowShouldClose(window)) {
        // ���ñ���ɫ
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // ���������� & �����¼�
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
