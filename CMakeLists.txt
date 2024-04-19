cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(image_processing)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

add_subdirectory(tests)