//
// Created by Bianca Mihai on 21.05.2026.
//

#include "Shop.h"
#include "Resident.h"
#include "InsufficientFundsException.h"
#include <iostream>

Shop::Shop() {
    addEntry("Bed",      "Restores energy",           0);
    addEntry("Sofa",     "Boosts happiness",          200);
    addEntry("Fridge",   "Restores hunger",           0);
    addEntry("Shower",   "Restores hygiene",          0);
    addEntry("Desk",     "Earn $30 per use",          150);
    addEntry("Computer", "Earn $60 per use",          500);
    addEntry("TV",       "Boosts happiness",          300);
    addEntry("Plant",    "Daily happiness boost",     50);
    addEntry("Painting", "Daily happiness boost",     100);
}

void Shop::addEntry(const std::string& itemType, const std::string& description, int cost) {
    catalog.add({itemType, description, cost});
}

std::unique_ptr<Item> Shop::buyItem(const std::string& itemType, Resident& resident) {
    for (int i = 0; i < catalog.getSize(); i++) {
        const ShopEntry& entry = catalog.get(i);
        if (entry.itemType == itemType) {
            if (resident.getMoney() < entry.cost) {
                throw InsufficientFundsException(resident.getMoney(), entry.cost);
            }
            resident.spendMoney(entry.cost);
            resident.addLog("Bought " + itemType + " for $" + std::to_string(entry.cost));
            return ItemFactory::create(itemType);
        }
    }
    throw std::runtime_error("Item not found in shop: " + itemType);
}

void Shop::printCatalog() const {
    std::cout << " SHOP :\n";
    for (int i = 0; i < catalog.getSize(); i++) {
        const ShopEntry& entry = catalog.get(i);
        std::cout << "- " << entry.itemType
                  << " | " << entry.description
                  << " | $" << entry.cost << "\n";
    }
}

const Inventory<ShopEntry>& Shop::getCatalog() const {
    return catalog;
}