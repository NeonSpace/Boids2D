cmake_minimum_required(VERSION 3.31)
project(Boids2D)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
set(CMAKE_CXX_STANDARD 20)

add_executable(Boids2D main.cpp
        Simulation2D.cpp
        Simulation2D.hpp
        Boid.cpp
        Boid.hpp
        customEnums.hpp
        CoordinateTranslator.cpp
        CoordinateTranslator.hpp
)

target_link_libraries(Boids2D sfml-graphics sfml-window sfml-system)
