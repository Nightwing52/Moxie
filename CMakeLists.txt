#you should include all of these into your CMakeMods folder
#https://github.com/Kitware/CMake/tree/master/Modules
#Bullet: https://github.com/Kitware/CMake/blob/master/Modules/FindBullet.cmake
#https://github.com/Kitware/CMake/blob/master/Modules/FindPackageMessage.cmake
#https://github.com/Kitware/CMake/blob/master/Modules/FindPackageHandleStandardArgs.cmake
#https://github.com/Kitware/CMake/blob/master/Modules/CMakeParseArguments.cmake
#Have a CMake module for SDL2 and glm as well

cmake_minimum_required(VERSION 3.0)
project("windfall" LANGUAGES CXX VERSION 0.02)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeMods")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(Bullet REQUIRED)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(
        ${INCLUDE_DIR}
        ${SDL2_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
	${BULLET_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

set(SOURCES
        src/main.cpp
        src/Framework/Display.cpp
        src/Framework/Input.cpp
        src/Framework/Shader.cpp
        src/Framework/Mesh.cpp
	include/Moxie.h
	include/MoxieCore/ChatterBox.h
	include/MoxieCore/Display.h
	include/MoxieCore/Input.h
	include/MoxieCore/Mesh.h
	include/MoxieCore/Shader.h
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${OPENGL_LIBRARIES}
	${BULLET_LIBRARIES}
        ${GLEW_LIBRARIES}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)
install(DIRECTORY res/ DESTINATION share/windfall)
