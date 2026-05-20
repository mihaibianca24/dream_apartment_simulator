//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Desk.h"
#include "Resident.h"

Desk::Desk(const std::string& name, int cost, int comfortBonus, int moneyEarned)
    : Appliance(name, cost, comfortBonus), moneyEarned(moneyEarned) {}

Desk::Desk(const Desk& obj)
    : Appliance(obj), moneyEarned(obj.moneyEarned) {}

Desk& Desk::operator=(const Desk& obj) {
    if (this != &obj) {
        Appliance::operator=(obj);
        moneyEarned = obj.moneyEarned;
    }
    return *this;
}

Desk::~Desk() = default;

void Desk::activate(Resident& resident) {
    resident.addMoney(moneyEarned);
    resident.modifyEnergy(-20);
    resident.modifyHappiness(-10);
}

std::string Desk::getDescription() const {
    return getName() + " (Desk) | Comfort: " + std::to_string(getComfortBonus()) +
           " | Earns: $" + std::to_string(moneyEarned);
}