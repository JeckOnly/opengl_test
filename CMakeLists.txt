cmake_minimum_required(VERSION 3.31)
project(cpp_p)

set(CMAKE_CXX_STANDARD 20)

# 你的可执行文件
add_executable(cpp_p
        main.cpp
        student.cpp
        test.cpp
)

include(FetchContent)

# glfw
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4          # 指定版本号
)

FetchContent_MakeAvailable(glfw)

add_library(glad ${CMAKE_SOURCE_DIR}/src/gl.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/include/include_glad)


target_link_libraries(cpp_p PRIVATE glad glfw)


# Windows 下要加 OpenGL 系统库
if (WIN32)
    target_link_libraries(cpp_p PRIVATE opengl32)
endif()


