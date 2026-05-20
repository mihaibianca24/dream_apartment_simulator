//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Appliance.h"
#include "Resident.h"
#include "Item.h"

Appliance::Appliance(const std::string& name, int cost, int comfortBonus)
    : Item(name, cost), isActive(false), comfortBonus(comfortBonus) {}

Appliance::Appliance(const Appliance& obj)
    : Item(obj), isActive(obj.isActive), comfortBonus(obj.comfortBonus) {}

Appliance& Appliance::operator=(const Appliance& obj) {
    if (this != &obj) {
        Item::operator=(obj);
        isActive = obj.isActive;
        comfortBonus = obj.comfortBonus;
    }
    return *this;
}

Appliance::~Appliance() = default;

bool Appliance::getIsActive() const {
    return isActive;
}

int Appliance::getComfortBonus() const {
    return comfortBonus;
}

void Appliance::setIsActive(bool value) {
    isActive = value;
}

void Appliance::applyEffect(Resident& resident) {
    if (isActive) activate(resident);
}