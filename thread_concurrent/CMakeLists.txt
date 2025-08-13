cmake_minimum_required(VERSION 3.5)

project(thread_concurrent LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Concurrent REQUIRED)

add_executable(thread_concurrent
  main.cpp
)
target_link_libraries(thread_concurrent
    Qt5::Core
    Qt5::Concurrent
)




