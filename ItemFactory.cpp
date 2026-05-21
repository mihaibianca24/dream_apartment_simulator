//
// Created by Bianca Mihai on 21.05.2026.
//

#include "ItemFactory.h"
#include "Bed.h"
#include "Sofa.h"
#include "Fridge.h"
#include "Shower.h"
#include "Desk.h"
#include "Computer.h"
#include "TV.h"
#include "Plant.h"
#include "Painting.h"

std::unique_ptr<Item> ItemFactory::create(const std::string& type) {
    if (type == "Bed")      return std::make_unique<Bed>();
    if (type == "Sofa")     return std::make_unique<Sofa>();
    if (type == "Fridge")   return std::make_unique<Fridge>();
    if (type == "Shower")   return std::make_unique<Shower>();
    if (type == "Desk")     return std::make_unique<Desk>();
    if (type == "Computer") return std::make_unique<Computer>();
    if (type == "TV")       return std::make_unique<TV>();
    if (type == "Plant")    return std::make_unique<Plant>();
    if (type == "Painting") return std::make_unique<Painting>();
    throw std::runtime_error("Unknown item type: " + type);
}