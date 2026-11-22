cmake_minimum_required(VERSION 3.16)

project(HelloQT2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 让 clangd / IntelliSense 能读取编译参数
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

# 如果 .ui 不在对应 .cpp 同目录，告诉 AUTOUIC 去哪找
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})

qt_add_executable(HelloQT2
    include/Sender.h
    include/Reciever.h
    include/Dialog.h
    include/Types.h

    src/Sender.cpp
    src/Reciever.cpp
    src/Dialog.cpp
    src/Types.cpp
    src/main.cpp

    dialog.ui
)

target_include_directories(HelloQT2 PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(HelloQT2 PRIVATE Qt6::Widgets)