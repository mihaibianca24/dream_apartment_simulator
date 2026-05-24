//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_INVENTORY_H
#define DREAM_APARTMENT_SIMULATOR_INVENTORY_H
#include <vector>
#include <stdexcept>

template<typename T>
class Inventory {
private:
    std::vector<T> items;
    int maxCapacity;
public:
    explicit Inventory(int maxCapacity = 100)
        : maxCapacity(maxCapacity) {}

    void add(const T& item) {
        if ((int)items.size() >= maxCapacity)
            throw std::runtime_error("Inventory is full");
        items.push_back(item);
    }

    void remove(int index) {
        if (index < 0 || index >= (int)items.size())
            throw std::out_of_range("Invalid index");
        items.erase(items.begin() + index);
    }

    T& get(int index) {
        if (index < 0 || index >= (int)items.size())
            throw std::out_of_range("Invalid index");
        return items[index];
    }

    const T& get(int index) const {
        if (index < 0 || index >= (int)items.size())
            throw std::out_of_range("Invalid index");
        return items[index];
    }

    int getSize() const { return (int)items.size(); }
    bool isEmpty() const { return items.empty(); }
    bool isFull() const { return (int)items.size() >= maxCapacity; }

    void clear() { items.clear(); }
};

#endif //DREAM_APARTMENT_SIMULATOR_INVENTORY_H