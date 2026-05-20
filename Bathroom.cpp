//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Bathroom.h"

Bathroom::Bathroom() : Room("Bathroom", 2) {}

std::string Bathroom::getDescription() const {
    return "Bathroom: \n" + Room::getDescription();
}