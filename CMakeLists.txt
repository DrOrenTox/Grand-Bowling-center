cmake_minimum_required(VERSION 3.25)

project(grand-bowling-center)

find_package(Geode REQUIRED)

# Cleaned up old architecture tags to prevent Geode v5 compile breaks
add_geode_mod(
    ${PROJECT_NAME}
    SOURCES src/main.cpp
)
