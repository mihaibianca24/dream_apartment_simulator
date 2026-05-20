//
// Created by Bianca Mihai on 20.05.2026.
//

#include "Room.h"
#include "Resident.h"
#include <algorithm>

Room::Room(const std::string& name, int maxSlots)
    : Entity(name), maxSlots(maxSlots) {}

std::string Room::getRoomName() const {
    return getName();
}

int Room::getMaxSlots() const {
    return maxSlots;
}

int Room::getOccupiedSlots() const {
    int count = 0;
    for (const auto& slot : slots) {
        if (slot != nullptr) count++;
    }
    return count;
}

bool Room::addItem(std::unique_ptr<Item> item) {
    if (getOccupiedSlots() >= maxSlots) {
        throw std::runtime_error("No available slots in " + getName());
    }
    slots.push_back(std::move(item));
    return true;
}

std::unique_ptr<Item> Room::removeItem(const std::string& itemName) {
    for (auto it = slots.begin(); it != slots.end(); ++it) {
        if ((*it) && (*it)->getName() == itemName) {
            std::unique_ptr<Item> removed = std::move(*it);
            slots.erase(it);
            return removed;
        }
    }
    return nullptr;
}

void Room::applyAllEffects(Resident& resident) {
    for (auto& slot : slots) {
        if (slot != nullptr) {
            slot->applyEffect(resident);
        }
    }
}

int Room::getComfortScore() const {
    int score = 0;
    for (const auto& slot : slots) {
        if (slot != nullptr) {
            score += slot->getComfortBonus();
        }
    }
    return score;
}

void Room::update(int deltaSeconds) {
    for (auto& slot : slots) {
        if (slot != nullptr) {
            slot->update(deltaSeconds);
        }
    }
}

std::string Room::getDescription() const {
    std::string desc = getName() + " [" +
                       std::to_string(getOccupiedSlots()) + "/" +
                       std::to_string(maxSlots) + " slots]\n";
    for (const auto& slot : slots) {
        if (slot != nullptr) {
            desc += "  - " + slot->getDescription() + "\n";
        }
    }
    return desc;
}