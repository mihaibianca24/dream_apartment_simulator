//
// Created by Bianca Mihai on 19.05.2026.
//

#include "Furniture.h"

Furniture& Furniture::operator=(const Furniture& obj) {
    if (this != &obj) {
        Item::operator=(obj);
        comfortBonus = obj.comfortBonus;
    }
    return *this;
}

Furniture::~Furniture() = default;

int Furniture::getComfortBonus() const {
    return comfortBonus;
}