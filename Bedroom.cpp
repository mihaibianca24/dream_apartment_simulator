//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Bedroom.h"

Bedroom::Bedroom() : Room("Bedroom", 4) {}

std::string Bedroom::getDescription() const {
    return " Bedroom : \n" + Room::getDescription();
}