cmake_minimum_required(VERSION 3.16)
project(copilot-token-abuse CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(copilottokenabuse
    src/main.cpp
    src/pool.cpp
    src/rotate.cpp
    src/proxy.cpp
    src/cli.cpp
)

target_include_directories(copilottokenabuse PRIVATE include)

if(WIN32)
    target_link_libraries(copilottokenabuse PRIVATE userenv)
endif()
