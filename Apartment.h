//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_APARTMENT_H
#define DREAM_APARTMENT_SIMULATOR_APARTMENT_H
#include <iostream>
#include <memory>
#include "Bedroom.h"
#include "LivingRoom.h"
#include "Bathroom.h"
#include "Resident.h"

class Apartment :public Entity{
private:
    std::unique_ptr<Bedroom> bedroom;
    std::unique_ptr<LivingRoom> livingRoom;
    std::unique_ptr<Bathroom> bathroom;
    Resident& resident;
public:
    Apartment(const std::string& name, Resident& resident);

    Bedroom& getBedroom();
    LivingRoom& getLivingRoom();
    Bathroom& getBathroom();

    void update(int deltaSeconds) override;

    int getDreamLevel() const;

    std::string getDescription() const override;

};


#endif //DREAM_APARTMENT_SIMULATOR_APARTMENT_H