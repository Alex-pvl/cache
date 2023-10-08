cmake_minimum_required(VERSION 3.26)
project(cache)

set(CMAKE_CXX_STANDARD 11)

add_executable(cache main.cpp
        provider/CacheProvider.cpp
        provider/lib/CacheProvider.h
        provider/FIFOProvider.cpp
        provider/lib/FIFOProvider.h)
