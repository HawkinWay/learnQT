cmake_minimum_required(VERSION 3.16)

project(HelloQT4 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 让 clangd / IntelliSense 能读取编译参数
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Quick)

qt_standard_project_setup()

# 如果 .ui 不在对应 .cpp 同目录，告诉 AUTOUIC 去哪找
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})

qt_add_executable(HelloQT4
    include/WorkerThread.h
    include/DataProcessor.h 
    include/DataProcessorWorker.h

    src/WorkerThread.cpp
    src/DataProcessor.cpp 
    src/DataProcessorWorker.cpp
    src/main.cpp
)

qt_add_qml_module(HelloQT4
    URI DataProcessor
    VERSION 1.0
    SOURCES
        include/DataProcessor.h 
        include/DataProcessorWorker.h
        src/DataProcessor.cpp 
        src/DataProcessorWorker.cpp
    QML_FILES
        src/Main.qml
        src/ThreadedProgressBar.qml
)

target_include_directories(HelloQT4 PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(HelloQT4 PRIVATE Qt6::Widgets Qt6::Quick)