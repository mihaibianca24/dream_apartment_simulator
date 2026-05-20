//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Painting.h"
#include "Resident.h"

Painting::Painting(const std::string& name, int cost, int comfortBonus, int happinessBonus)
    : Decoration(name, cost, comfortBonus, happinessBonus) {}

Painting::Painting(const Painting& obj) : Decoration(obj) {}

Painting& Painting::operator=(const Painting& obj) {
    if (this != &obj) Decoration::operator=(obj);
    return *this;
}

Painting::~Painting() = default;

void Painting::dailyEffect(Resident& resident) {
    resident.modifyHappiness(getHappinessBonus());
}

std::string Painting::getDescription() const {
    return getName() + " (Painting) | Comfort: " + std::to_string(getComfortBonus()) +
           " | Daily happiness: +" + std::to_string(getHappinessBonus());
}