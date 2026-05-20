//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_DESK_H
#define DREAM_APARTMENT_SIMULATOR_DESK_H
#include "Appliance.h"

class Desk : public Appliance {
private:
    int moneyEarned;
public:
    Desk(const std::string& name = "Desk", int cost = 150, int comfortBonus = 5, int moneyEarned = 30);
    Desk(const Desk& obj);
    Desk& operator=(const Desk& obj);
    ~Desk();

    void activate(Resident& resident) override;
    std::string getDescription() const override;
};

#endif //DREAM_APARTMENT_SIMULATOR_DESK_H