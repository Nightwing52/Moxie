cmake_minimum_required(VERSION 3.0)
project("windfall" LANGUAGES CXX VERSION 0.01)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${SDL2_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
)

set(SOURCES
        main.cpp
        Framework/Display.cpp
        Framework/Input.cpp
        Framework/Shader.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
