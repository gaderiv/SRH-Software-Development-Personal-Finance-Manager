cmake_minimum_required(VERSION 3.14)

project("Personal_Finance_Manager")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} "main.cpp")

add_subdirectory(PFMLib)
add_subdirectory(UnitTests)

target_link_libraries(${PROJECT_NAME} PFMLib)