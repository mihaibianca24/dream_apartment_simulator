#include "Item.h"

Item::Item(const std::string& name, int cost)
    : Entity(name), cost(cost), isPlaced(false) {}

Item::Item(const Item& other)
    : Entity(other), cost(other.cost), isPlaced(other.isPlaced) {}

Item& Item::operator=(const Item& other) {
    if (this != &other) {
        Entity::operator=(other);
        cost = other.cost;
        isPlaced = other.isPlaced;
    }
    return *this;
}

Item::~Item() = default;

int Item::getCost() const {
    return cost;
}

bool Item::getIsPlaced() const {
    return isPlaced;
}

void Item::setIsPlaced(bool value) {
    isPlaced = value;
}
