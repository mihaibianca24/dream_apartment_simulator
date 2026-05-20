//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Decoration.h"
#include "Resident.h"

Decoration::Decoration(const std::string& name, int cost, int comfortBonus, int happinessBonus)
    : Item(name, cost), happinessBonus(happinessBonus) {}

Decoration::Decoration(const Decoration& obj)
    : Item(obj), happinessBonus(obj.happinessBonus) {}

Decoration& Decoration::operator=(const Decoration& obj) {
    if (this != &obj) {
        Item::operator=(obj);
        happinessBonus = obj.happinessBonus;
    }
    return *this;
}

Decoration::~Decoration() = default;

int Decoration::getHappinessBonus() const {
    return happinessBonus;
}

int Decoration::getComfortBonus() const {
    return comfortBonus;
}

void Decoration::applyEffect(Resident& resident) {
    dailyEffect(resident);
}