//
// Created by Bianca Mihai on 19.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_FURNITURE_H
#define DREAM_APARTMENT_SIMULATOR_FURNITURE_H
#include <string>

#include "Item.h"


class Furniture :public Item{
private:
    int comfortBonus;
public:
    Furniture(const std::string& name, int cost, int comfortBonus) : Item(name, cost), comfortBonus(comfortBonus) {}
    Furniture(const Furniture& obj) : Item(obj){}
    Furniture& operator=(const Furniture& obj);
    ~Furniture();

    int getComfortBonus() const;
    virtual void applyEffect(Resident &resident) =0;
    virtual std::string getDescription() const =0;
    void update(int deltaSeconds) override{}
};


#endif //DREAM_APARTMENT_SIMULATOR_FURNITURE_H