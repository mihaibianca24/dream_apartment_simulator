//
// Created by Bianca Mihai on 21.05.2026.
//

#include "Apartment.h"
#include <algorithm>

Apartment::Apartment(const std::string& name, Resident& resident)
    : Entity(name), resident(resident),
      bedroom(std::make_unique<Bedroom>()),
      livingRoom(std::make_unique<LivingRoom>()),
      bathroom(std::make_unique<Bathroom>()) {}

Bedroom& Apartment::getBedroom() {
    return *bedroom;
}

LivingRoom& Apartment::getLivingRoom() {
    return *livingRoom;
}

Bathroom& Apartment::getBathroom() {
    return *bathroom;
}

void Apartment::update(int deltaSeconds) {
    bedroom->update(deltaSeconds);
    livingRoom->update(deltaSeconds);
    bathroom->update(deltaSeconds);
}

int Apartment::getDreamLevel() const {
    int total = bedroom->getComfortScore() +
                livingRoom->getComfortScore() +
                bathroom->getComfortScore();
    return std::min(100, (total * 100) / 300);
}

std::string Apartment::getDescription() const {
    return " Apartment: " + getName() + "\n"
           "Dream Level: " + std::to_string(getDreamLevel()) + "%\n" +
           bedroom->getDescription() +
           livingRoom->getDescription() +
           bathroom->getDescription();
}