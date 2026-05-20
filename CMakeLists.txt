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
        Furniture.h
        Bed.cpp
        Bed.h
        Sofa.cpp
        Sofa.h
        Fridge.cpp
        Fridge.h
        Shower.cpp
        Shower.h
        Appliance.cpp
        Appliance.h
        Desk.cpp
        Desk.h
        Computer.cpp
        Computer.h
        TV.cpp
        TV.h
        Decoration.cpp
        Decoration.h
        Plant.cpp
        Plant.h
        Painting.cpp
        Painting.h)
