cmake_minimum_required(VERSION 3.29)
project(fusion_bridge)

set(CMAKE_CXX_STANDARD 20)

add_executable(fusion_bridge src/main.cpp
        src/network/server.cpp
        include/network/server.h)

find_package(Poco REQUIRED Net Foundation)

target_link_libraries(fusion_bridge
    PRIVATE Poco::Net Poco::Foundation
)