cmake_minimum_required(VERSION 3.26)
project(Socket_Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Socket_Server main.cpp)
if(WIN32)
    target_link_libraries(Socket_Server wsock32 ws2_32)
endif()
