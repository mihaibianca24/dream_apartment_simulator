//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_BATHROOM_H
#define DREAM_APARTMENT_SIMULATOR_BATHROOM_H
#include "Room.h"

class Bathroom : public Room {
public:
    Bathroom();
    ~Bathroom() override = default;
    std::string getDescription() const override;
};
#endif //DREAM_APARTMENT_SIMULATOR_BATHROOM_H