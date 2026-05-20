//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_FRIDGE_H
#define DREAM_APARTMENT_SIMULATOR_FRIDGE_H
#include "Furniture.h"

class Fridge : public Furniture {
private:
    int hungerRestore;
public:
    Fridge(const std::string& name = "Fridge", int cost = 0, int comfortBonus = 10, int hungerRestore = 25);
    Fridge(const Fridge& obj);
    Fridge& operator=(const Fridge& obj);
    ~Fridge();

    void applyEffect(Resident& resident) override;
    std::string getDescription() const override;
};

#endif //DREAM_APARTMENT_SIMULATOR_FRIDGE_H