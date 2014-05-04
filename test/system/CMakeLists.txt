cmake_minimum_required(VERSION 2.8)
SET( CMAKE_CXX_COMPILER "g++-4.8" )
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

LINK_DIRECTORIES( . test/ test/system/ )
INCLUDE_DIRECTORIES( . .. ../.. )


add_executable(plain_mc plain_mc.cpp)



TARGET_LINK_LIBRARIES(plain_mc m)

