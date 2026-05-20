//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_LIVINGROOM_H
#define DREAM_APARTMENT_SIMULATOR_LIVINGROOM_H
#include "Room.h"

class LivingRoom : public Room {
public:
    LivingRoom();
    ~LivingRoom() override = default;
    std::string getDescription() const override;
};
#endif //DREAM_APARTMENT_SIMULATOR_LIVINGROOM_H