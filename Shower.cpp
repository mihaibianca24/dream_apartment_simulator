//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Shower.h"
#include "Resident.h"

Shower::Shower(const std::string& name, int cost, int comfortBonus, int hygieneRestore)
    : Furniture(name, cost, comfortBonus), hygieneRestore(hygieneRestore) {}

Shower::Shower(const Shower& obj)
    : Furniture(obj), hygieneRestore(obj.hygieneRestore) {}

Shower& Shower::operator=(const Shower& obj) {
    if (this != &obj) {
        Furniture::operator=(obj);
        hygieneRestore = obj.hygieneRestore;
    }
    return *this;
}

Shower::~Shower() = default;

void Shower::applyEffect(Resident& resident) {
    resident.modifyHygiene(hygieneRestore);
    resident.modifyHappiness(5);
}

std::string Shower::getDescription() const {
    return getName() + " (Shower) | Comfort: " + std::to_string(getComfortBonus()) +
           " | Hygiene restore: " + std::to_string(hygieneRestore);
}