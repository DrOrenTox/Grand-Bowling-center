cmake_minimum_required(VERSION 3.25)

project(grand-bowling-center)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    X86
    X64
    ARM
    SOURCES src/main.cpp
)

