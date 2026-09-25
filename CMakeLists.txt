cmake_minimum_required(VERSION 3.28)

project(IOT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    IOT
    src/main.cpp
    src/Server.cpp
    src/Sensor.cpp
    src/Scheduler.cpp
    )