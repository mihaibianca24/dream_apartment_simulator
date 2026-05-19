//
// Created by Bianca Mihai on 19.05.2026.
//

#include "Sofa.h"
#include "Resident.h"

Sofa::Sofa(const std::string& name, int cost, int comfortBonus, int happinessRestore)
    : Furniture(name, cost, comfortBonus), happinessRestore(happinessRestore) {}

Sofa::Sofa(const Sofa& obj)
    : Furniture(obj), happinessRestore(obj.happinessRestore) {}

Sofa& Sofa::operator=(const Sofa& obj) {
    if (this != &obj) {
        Furniture::operator=(obj);
        happinessRestore = obj.happinessRestore;
    }
    return *this;
}

Sofa::~Sofa() = default;

void Sofa::applyEffect(Resident& resident) {
    resident.modifyHappiness(happinessRestore);
}

std::string Sofa::getDescription() const {
    return getName() + " (Sofa) | Comfort: " + std::to_string(getComfortBonus()) +
       " | Happiness restore: " + std::to_string(happinessRestore);
}