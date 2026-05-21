cmake_minimum_required(VERSION 3.16)
project(dream_apartment_simulator)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

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
        Room.h
        Bedroom.cpp
        Bedroom.h
        Livingroom.cpp
        Livingroom.h
        Bathroom.cpp
        Bathroom.h
        Apartment.cpp
        Apartment.h
        InsufficientFundsException.h
        SlotOccupiedException.h
        Inventory.h
        ItemFactory.cpp
        ItemFactory.h
        Shop.cpp
        Shop.h
        TimeSystem.cpp
        TimeSystem.h
        EventSystem.cpp
        EventSystem.h
        IEventListener.h
        GameEngine.cpp
        GameEngine.h
)