cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 20)

project(fusion_bridge)



include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

file(GLOB_RECURSE HEADER_SOURCE "include/**/*.hpp")
file(GLOB_RECURSE MAIN_SOURCE "src/**/*.cpp")
file(GLOB_RECURSE LIB_SOURCE "lib/**/*.cpp")
file(GLOB MAIN_FILE "src/main.cpp")

message(STATUS "Debug")
message(STATUS "- Sources:")
message(STATUS "-- Include: ${HEADER_SOURCE}")

message(STATUS "-- Src: ${MAIN_SOURCE}")
message(STATUS "-- Main: ${MAIN_FILE}")

find_package(Poco REQUIRED Net Foundation)

message(STATUS "- Libraries:")
message(STATUS "-- Local: ${LIB_SOURCE}")
message(STATUS "-- Poco: ${Poco_LIBRARIES}")


add_executable(fusion_bridge
        ${MAIN_FILE}
        ${MAIN_SOURCE}
        ${HEADER_SOURCE}
        ${LIB_SOURCE}
)

target_link_libraries(fusion_bridge
        PRIVATE Poco::Net Poco::Foundation
)


#------------------------------- UNIT TEST SETUP -------------------------------
message(STATUS "Test")
message(STATUS "- Sources:")
file(GLOB_RECURSE TEST_SOURCE "test/**/*.cpp")
message(STATUS "-- Main: ${TEST_SOURCE}")


message(STATUS "- Libraries:")
find_package(GTest REQUIRED)
message(STATUS "-- Gtest: ${GTest_LIBRARIES}")

message(STATUS "----------------------------------------------")

add_executable(unit_test
        ${MAIN_SOURCE}
        ${HEADER_SOURCE}
        ${LIB_SOURCE}
        ${TEST_SOURCE}
)

target_link_libraries(unit_test
        PRIVATE Poco::Net Poco::Foundation
        GTest::gtest_main
)

enable_testing()

add_test(NAME GeneralTest COMMAND unit_test)