//
// Created by Bianca Mihai on 19.05.2026.
//

#include "Bed.h"
#include "Resident.h"

Bed::Bed(const std::string& name, int cost, int comfortBonus, int energyRestore)
    : Furniture(name, cost, comfortBonus), energyRestore(energyRestore) {}

Bed::Bed(const Bed& obj)
    : Furniture(obj), energyRestore(obj.energyRestore) {}

Bed& Bed::operator=(const Bed& obj) {
    if (this != &obj) {
        Furniture::operator=(obj);
        energyRestore = obj.energyRestore;
    }
    return *this;
}

Bed::~Bed() = default;

void Bed::applyEffect(Resident& resident) {
    resident.modifyEnergy(energyRestore);
}

std::string Bed::getDescription() const {
    return getName() + " (Bed) | Comfort: " + std::to_string(getComfortBonus()) +
           " | Energy restore: " + std::to_string(energyRestore);
}