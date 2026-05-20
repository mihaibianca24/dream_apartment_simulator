//
// Created by Bianca Mihai on 20.05.2026.
//

#include "TV.h"
#include "Resident.h"

TV::TV(const std::string& name, int cost, int comfortBonus, int happinessRestore)
    : Appliance(name, cost, comfortBonus), happinessRestore(happinessRestore) {}

TV::TV(const TV& obj)
    : Appliance(obj), happinessRestore(obj.happinessRestore) {}

TV& TV::operator=(const TV& obj) {
    if (this != &obj) {
        Appliance::operator=(obj);
        happinessRestore = obj.happinessRestore;
    }
    return *this;
}

TV::~TV() = default;

void TV::activate(Resident& resident) {
    resident.modifyHappiness(happinessRestore);
    resident.modifyEnergy(-5);
}

std::string TV::getDescription() const {
    return getName() + " (TV) | Comfort: " + std::to_string(getComfortBonus()) +
           " | Happiness restore: " + std::to_string(happinessRestore);
}