//
// Created by Bianca Mihai on 19.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_ITEM_H
#define DREAM_APARTMENT_SIMULATOR_ITEM_H
#include "Entity.h"
class Resident;

class Item : public Entity{
private:
    int cost;
    bool isPlaced;
public:
    Item(const std::string &name, int cost);
    Item(const Item& item);
    Item & operator=(const Item& item);
    ~Item();

    int getCost() const;
    bool getIsPlaced() const;

    void setIsPlaced(bool value);
    virtual void applyEffect(Resident &resident)=0;
    std::string getDescription() const override=0;
    void update(int deltaSeconds) override {}

};


#endif //DREAM_APARTMENT_SIMULATOR_ITEM_H