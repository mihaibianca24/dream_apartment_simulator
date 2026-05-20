//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_SHOWER_H
#define DREAM_APARTMENT_SIMULATOR_SHOWER_H
#include "Furniture.h"

class Shower : public Furniture {
private:
    int hygieneRestore;
public:
    Shower(const std::string& name = "Shower", int cost = 0, int comfortBonus = 10, int hygieneRestore = 40);
    Shower(const Shower& obj);
    Shower& operator=(const Shower& obj);
    ~Shower();

    void applyEffect(Resident& resident) override;
    std::string getDescription() const override;
};
#endif //DREAM_APARTMENT_SIMULATOR_SHOWER_H