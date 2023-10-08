cmake_minimum_required(VERSION 3.26)
project(cache)

set(CMAKE_CXX_STANDARD 11)

add_executable(cache main.cpp
        lib/CacheProvider.h
        provider/FIFOProvider.cpp
        lib/FIFOProvider.h
        provider/LRUProvider.cpp
        lib/LRUProvider.h
        provider/RANDProvider.cpp
        lib/RANDProvider.h
        CachingService.cpp
        lib/CachingService.h)
