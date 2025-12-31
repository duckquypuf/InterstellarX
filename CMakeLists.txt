cmake_minimum_required(VERSION 4.1.2)
project(engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -DNDEBUG -flto")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(include src thirdparty)

file(GLOB IMGUI_SOURCES
    thirdparty/imgui/*.cpp
)

file(GLOB INCLUDE_SOURCES
    include/*.cpp
)

add_executable(engine
    src/main.cpp
    ${INCLUDE_SOURCES}
    src/stb_impl.cpp
    thirdparty/glad.c
    ${IMGUI_SOURCES}
)

target_link_libraries(engine
    glfw
    OpenGL::GL
)

add_definitions(-Wno-deprecated-declarations)
