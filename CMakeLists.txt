cmake_minimum_required(VERSION 3.5)
project(cfightlog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/aes.h
    include/cfg.h
    include/com.h
    include/handleTrd.h
    include/sendMgr.h
    include/sendTrd.h
    source/aes.cpp
    source/cfg.cpp
    source/handleTrd.cpp
    source/main.cpp
    source/sendMgr.cpp
    source/sendTrd.cpp)

add_executable(cfightlog ${SOURCE_FILES})