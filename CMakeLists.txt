cmake_minimum_required(VERSION 3.0)
project("Moxie" LANGUAGES CXX VERSION 0.02)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeMods")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(
        ${INCLUDE_DIR}
        ${SDL2_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

set(SOURCES
    src/main.cpp
    src/Display.cpp
    src/Input.cpp
    src/Shader.cpp
    src/Mesh.cpp
	src/Singleton.cpp
	src/Generic.cpp
	include/Moxie.h
	include/Display.h
	include/Input.h
	include/Mesh.h
	include/Shader.h
	include/Singleton.h
	include/Constants.h
	include/Generic.h
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)
install(DIRECTORY res/ DESTINATION share/moxie)
