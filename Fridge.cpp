//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Fridge.h"
#include "Resident.h"

Fridge::Fridge(const std::string& name, int cost, int comfortBonus, int hungerRestore)
    : Furniture(name, cost, comfortBonus), hungerRestore(hungerRestore) {}

Fridge::Fridge(const Fridge& obj)
    : Furniture(obj), hungerRestore(obj.hungerRestore) {}

Fridge& Fridge::operator=(const Fridge& obj) {
    if (this != &obj) {
        Furniture::operator=(obj);
        hungerRestore = obj.hungerRestore;
    }
    return *this;
}

Fridge::~Fridge() = default;

void Fridge::applyEffect(Resident& resident) {
    resident.modifyHunger(hungerRestore);
}

std::string Fridge::getDescription() const {
    return getName() + " (Fridge) | Comfort: " + std::to_string(getComfortBonus()) +
           " | Hunger restore: " + std::to_string(hungerRestore);
}