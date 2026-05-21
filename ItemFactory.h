//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_ITEMFACTORY_H
#define DREAM_APARTMENT_SIMULATOR_ITEMFACTORY_H
#include <memory>
#include <string>
#include "Item.h"

class ItemFactory {
public:
    static std::unique_ptr<Item> create(const std::string& type);
};
#endif //DREAM_APARTMENT_SIMULATOR_ITEMFACTORY_H