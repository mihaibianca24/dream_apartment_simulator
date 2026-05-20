//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_BEDROOM_H
#define DREAM_APARTMENT_SIMULATOR_BEDROOM_H
#include "Room.h"

class Bedroom : public Room {
public:
    Bedroom();
    ~Bedroom() override = default;
    std::string getDescription() const override;
};
#endif //DREAM_APARTMENT_SIMULATOR_BEDROOM_H