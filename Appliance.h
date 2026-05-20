//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_APPLIANCE_H
#define DREAM_APARTMENT_SIMULATOR_APPLIANCE_H
#include "Item.h"
class Resident;
class Appliance : public Item{
private :
    bool isActive;
    int comfortBonus;
public:
    Appliance(const std::string &name,int cost, int comfortBonus) ;
    Appliance(const Appliance &obj);
    Appliance &operator=(const Appliance &obj);
    virtual ~Appliance();

    bool getIsActive() const;
    int getComfortBonus() const;
    void setIsActive(bool value);

    virtual void activate(Resident& resident) = 0;
    void applyEffect(Resident& resident) override;
    virtual std::string getDescription() const = 0;
    void update(int deltaSeconds) override {}
};


#endif //DREAM_APARTMENT_SIMULATOR_APPLIANCE_H