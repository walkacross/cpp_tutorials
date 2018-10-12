cmake_minimum_required(VERSION 3.11)

project(hello_headers)

SET(SOURCE
    src/Hello.cpp
    src/main.cpp)

add_executable(hello_headers.exe ${SOURCE})

target_include_directories(hello_headers.exe
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/include)
