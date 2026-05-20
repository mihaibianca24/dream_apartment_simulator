//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Plant.h"
#include "Resident.h"
#include "Decoration.h"

Plant::Plant(const std::string& name, int cost, int comfortBonus, int happinessBonus)
    : Decoration(name, cost, comfortBonus, happinessBonus) {}

Plant::Plant(const Plant& obj) : Decoration(obj) {}

Plant& Plant::operator=(const Plant& obj) {
    if (this != &obj) Decoration::operator=(obj);
    return *this;
}

Plant::~Plant() = default;

void Plant::dailyEffect(Resident& resident) {
    resident.modifyHappiness(getHappinessBonus());
}

std::string Plant::getDescription() const {
    return getName() + " (Plant) | Comfort: " + std::to_string(getComfortBonus()) +
           " | Daily happiness: +" + std::to_string(getHappinessBonus());
}