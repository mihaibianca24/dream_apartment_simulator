//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_PLANT_H
#define DREAM_APARTMENT_SIMULATOR_PLANT_H
#include "Decoration.h"

class Plant : public Decoration {
public:
    Plant(const std::string& name = "Plant", int cost = 50, int comfortBonus = 5, int happinessBonus = 5);
    Plant(const Plant& obj);
    Plant& operator=(const Plant& obj);
    ~Plant();

    void dailyEffect(Resident& resident) override;
    std::string getDescription() const override;
};

#endif //DREAM_APARTMENT_SIMULATOR_PLANT_H