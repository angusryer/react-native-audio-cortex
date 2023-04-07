cmake_minimum_required(VERSION 3.4.1)

project(react-native-audio-cortex)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)

add_library(cpp
  SHARED
  ../cpp/react-native-audio-cortex.cpp
  cpp-adapter.cpp
)

find_package(oboe REQUIRED CONFIG)

# Specifies a path to native header files.
include_directories(
  ../cpp
)

# Link Oboe library to our cpp adapter
target_link_libraries(cpp oboe::oboe)