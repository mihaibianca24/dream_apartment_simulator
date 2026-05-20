//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_TV_H
#define DREAM_APARTMENT_SIMULATOR_TV_H
#include "Appliance.h"

class TV : public Appliance {
private:
    int happinessRestore;
public:
    TV(const std::string& name = "TV", int cost = 300, int comfortBonus = 15, int happinessRestore = 20);
    TV(const TV& obj);
    TV& operator=(const TV& obj);
    ~TV();

    void activate(Resident& resident) override;
    std::string getDescription() const override;
};

#endif //DREAM_APARTMENT_SIMULATOR_TV_H