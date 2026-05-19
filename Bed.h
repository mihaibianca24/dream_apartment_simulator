//
// Created by Bianca Mihai on 19.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_BED_H
#define DREAM_APARTMENT_SIMULATOR_BED_H
#include "Furniture.h"

class Bed : public Furniture{
private:
    int energyRestore;
public:
    Bed(const std::string& name = "Bed", int cost = 0, int comfortBonus = 20, int energyRestore = 30);
    Bed(const Bed & obj);
    Bed& operator=(const Bed & obj);
    ~Bed();

    void applyEffect(Resident & resident) override;
    std::string getDescription() const override;

};


#endif //DREAM_APARTMENT_SIMULATOR_BED_H