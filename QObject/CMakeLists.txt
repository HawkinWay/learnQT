cmake_minimum_required(VERSION 3.16)
project(HelloQT VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(HelloQT 
    include/MyProp.h
    include/MemMana.h

    src/MyProp.cpp
    src/MemMana.cpp
    src/main.cpp
)

target_include_directories(HelloQT PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(HelloQT PRIVATE Qt6::Widgets)