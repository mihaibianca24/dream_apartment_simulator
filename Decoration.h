//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_DECORATION_H
#define DREAM_APARTMENT_SIMULATOR_DECORATION_H
#include "Item.h"
class Resident;

class Decoration :public Item{
private :
    int happinessBonus;
    int comfortBonus;
public:
    Decoration(const std::string& name, int cost, int comfortBonus, int happinessBonus);
    Decoration(const Decoration &obj);
    Decoration &operator=(const Decoration &obj);
    virtual ~Decoration();

    int getHappinessBonus() const;

    virtual void dailyEffect(Resident& resident) = 0;
    void applyEffect(Resident& resident) override;
    virtual std::string getDescription() const = 0;
    void update(int deltaSeconds) override {}

};


#endif //DREAM_APARTMENT_SIMULATOR_DECORATION_H