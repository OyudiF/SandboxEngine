cmake_minimum_required(VERSION 3.2)
project(SandboxEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
)
FetchContent_MakeAvailable(SFML)

add_executable(SandboxEngine main.cpp
        include/State.h
        include/StateMachine.h
        src/StateMachine.cpp
)

target_include_directories(SandboxEngine PRIVATE include)

target_link_libraries(SandboxEngine PRIVATE SFML::Graphics SFML::Window SFML::System)