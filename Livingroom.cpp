//
// Created by Bianca Mihai on 20.05.2026.
//

#include "LivingRoom.h"

LivingRoom::LivingRoom() : Room("Living Room", 5) {}

std::string LivingRoom::getDescription() const {
    return "Living Room :\n" + Room::getDescription();
}