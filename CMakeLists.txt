cmake_minimum_required(VERSION 3.29)
project(Socket_Server C)

set(CMAKE_C_STANDARD 11)

add_executable(Socket_Server main.c)
if(WIN32)
    target_link_libraries(Socket_Server wsock32 ws2_32)
endif()
