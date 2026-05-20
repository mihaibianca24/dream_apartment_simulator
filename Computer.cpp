//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Computer.h"
#include "Resident.h"

Computer::Computer(const std::string& name, int cost, int comfortBonus, int moneyEarned)
    : Appliance(name, cost, comfortBonus), moneyEarned(moneyEarned) {}

Computer::Computer(const Computer& obj)
    : Appliance(obj), moneyEarned(obj.moneyEarned) {}

Computer& Computer::operator=(const Computer& obj) {
    if (this != &obj) {
        Appliance::operator=(obj);
        moneyEarned = obj.moneyEarned;
    }
    return *this;
}

Computer::~Computer() = default;

void Computer::activate(Resident& resident) {
    resident.addMoney(moneyEarned);
    resident.modifyEnergy(-25);
    resident.modifyHappiness(-5);
}

std::string Computer::getDescription() const {
    return getName() + " (Computer) | Comfort: " + std::to_string(getComfortBonus()) +
           " | Earns: $" + std::to_string(moneyEarned);
}