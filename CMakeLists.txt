cmake_minimum_required(VERSION 3.16)
project(dream_apartment_simulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(dream_apartment_simulator
        main.cpp
        Entity.cpp
        Item.cpp
        Resident.cpp
        Furniture.cpp
        Bed.cpp
        Sofa.cpp
        Fridge.cpp
        Shower.cpp
        Appliance.cpp
        Desk.cpp
        Computer.cpp
        TV.cpp
        Decoration.cpp
        Plant.cpp
        Painting.cpp
        Room.cpp
        Bedroom.cpp
        LivingRoom.cpp
        Bathroom.cpp
        Apartment.cpp
        Shop.cpp
        ItemFactory.cpp
        GameEngine.cpp
        TimeSystem.cpp
        EventSystem.cpp
        ConsoleUI.cpp
)