cmake_minimum_required(VERSION 2.8)

LINK_DIRECTORIES( . )
INCLUDE_DIRECTORIES( . .. ../.. )


add_executable(plain_mc plain_mc.cpp)



TARGET_LINK_LIBRARIES(plain_mc m)

