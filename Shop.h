//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_SHOP_H
#define DREAM_APARTMENT_SIMULATOR_SHOP_H
#include <string>
#include "Inventory.h"
#include "ItemFactory.h"

class Resident;
struct ShopEntry {
    std::string itemType;
    std::string description;
    int cost;
};

class Shop {
private:
    Inventory<ShopEntry> catalog;
public:
    Shop();

    void addEntry(const std::string& itemType, const std::string& description, int cost);
    std::unique_ptr<Item> buyItem(const std::string& itemType, Resident& resident);
    void printCatalog() const;

    const Inventory<ShopEntry>& getCatalog() const;
};
#endif //DREAM_APARTMENT_SIMULATOR_SHOP_H