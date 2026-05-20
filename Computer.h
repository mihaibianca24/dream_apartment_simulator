//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_COMPUTER_H
#define DREAM_APARTMENT_SIMULATOR_COMPUTER_H
#include "Appliance.h"

class Computer : public Appliance {
private:
    int moneyEarned;
public:
    Computer(const std::string& name = "Computer", int cost = 500, int comfortBonus = 10, int moneyEarned = 60);
    Computer(const Computer& obj);
    Computer& operator=(const Computer& obj);
    ~Computer();

    void activate(Resident& resident) override;
    std::string getDescription() const override;
};

#endif //DREAM_APARTMENT_SIMULATOR_COMPUTER_H