//
// Created by Bianca Mihai on 19.05.2026.
//

#include "Resident.h"
#include "Entity.h"
#include <algorithm>

Resident :: Resident() : Entity("Unknown"){
    this->energy=100;
    this->hunger=100;
    this->happiness=100;
    this->hygiene=100;
    this->money=500;
}
Resident :: Resident(const std::string &name) : Entity(name){
    this->energy=100;
    this->hunger=100;
    this->happiness=100;
    this->hygiene=100;
    this->money=500;
}
Resident :: Resident(const Resident &resident) : Entity(resident){
    this->energy=resident.energy;
    this->hunger=resident.hunger;
    this->happiness=resident.happiness;
    this->hygiene=resident.hygiene;
    this->money=resident.money;
}
Resident& Resident::operator=(const Resident& other) {
    if (this != &other) {
        Entity::operator=(other);
        energy = other.energy;
        hunger = other.hunger;
        happiness = other.happiness;
        hygiene = other.hygiene;
        money = other.money;
    }
    return *this;
}
Resident::~Resident() = default;

int Resident::getEnergy() const { return energy; }
int Resident::getHunger() const { return hunger; }
int Resident::getHappiness() const { return happiness; }
int Resident::getHygiene() const { return hygiene; }
int Resident::getMoney() const { return money; }

void Resident::modifyEnergy(int amount) {
    energy = std::clamp(energy + amount, 0, 100);
    if (amount > 0)
        activityLog.add("Energy +" + std::to_string(amount));
    else
        activityLog.add("Energy " + std::to_string(amount));
}
void Resident::modifyHunger(int amount) {
    hunger = std::clamp(hunger + amount, 0, 100);
    if (amount > 0)
        activityLog.add("Energy +" + std::to_string(amount));
    else
        activityLog.add("Energy " + std::to_string(amount));
}
void Resident::modifyHappiness(int amount) {
    happiness = std::clamp(happiness + amount, 0, 100);
    if (amount > 0)
        activityLog.add("Energy +" + std::to_string(amount));
    else
        activityLog.add("Energy " + std::to_string(amount));
}
void Resident::modifyHygiene(int amount) {
    hygiene = std::clamp(hygiene + amount, 0, 100);
    if (amount > 0)
        activityLog.add("Energy +" + std::to_string(amount));
    else
        activityLog.add("Energy " + std::to_string(amount));
}

void Resident::addMoney(int amount) {
    money += amount;
}

bool Resident::spendMoney(int amount) {
    if (money >= amount) {
        money -= amount;
        return true;
    }
    return false;
}

void Resident::update(int deltaSeconds) {
    modifyHunger(-1 * deltaSeconds);
    modifyHygiene(-1 * deltaSeconds);
    modifyEnergy(-1 * deltaSeconds);
    modifyHappiness(-1 * deltaSeconds);
}

std::string Resident::getDescription() const {
    return getName() +
           " | Energy: "    + std::to_string(energy) +
           " | Hunger: "    + std::to_string(hunger) +
           " | Happiness: " + std::to_string(happiness) +
           " | Hygiene: "   + std::to_string(hygiene) +
           " | Money: "     + std::to_string(money);
}

bool Resident::isDead() const {
    return energy <= 0;
}

void Resident::addLog(const std::string& message) {
    activityLog.add(message);
}

Inventory<std::string>& Resident::getActivityLog() {
    return activityLog;
}