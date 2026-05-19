cmake_minimum_required(VERSION 4.1)
project(dream_apartment_simulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(dream_apartment_simulator main.cpp
        Entity.cpp
        Entity.h
        Item.cpp
        Item.h
        Resident.cpp
        Resident.h
        Furniture.cpp
        Furniture.h)
