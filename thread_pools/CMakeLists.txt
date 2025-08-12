cmake_minimum_required(VERSION 3.5)

project(thread_pools LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(thread_pools
  main.cpp
  album.cpp
  album.h
  song.cpp
  song.h
  )
target_link_libraries(thread_pools Qt5::Core)
