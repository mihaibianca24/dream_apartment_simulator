//
// Created by Bianca Mihai on 19.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_SOFA_H
#define DREAM_APARTMENT_SIMULATOR_SOFA_H

#include "Furniture.h"

class Sofa : public Furniture{
private:
    int happinessRestore;
public:
    Sofa(const std::string& name = "Sofa", int cost = 200, int comfortBonus = 15, int happinessRestore = 20);
    Sofa(const Sofa & obj);
    Sofa& operator=(const Sofa & obj);
    ~Sofa();

    void applyEffect(Resident & resident) override;
    std::string getDescription() const override;

};



#endif //DREAM_APARTMENT_SIMULATOR_SOFA_H