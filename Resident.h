//
// Created by Bianca Mihai on 19.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_RESIDENT_H
#define DREAM_APARTMENT_SIMULATOR_RESIDENT_H
#include "Entity.h"
#include "Inventory.h"

class Resident : public Entity {
    private:
    int energy;
    int hunger;
    int happiness;
    int hygiene;
    int money;
    Inventory<std::string> activityLog;
    int tickAccumulator;
public:
    Resident();
    Resident(const std::string& name);
    Resident(const Resident &resident);
    Resident & operator=(const Resident &resident);
    ~Resident();

    int getEnergy() const;
    int getHunger() const;
    int getHappiness() const;
    int getHygiene() const;
    int getMoney() const;

    void modifyEnergy(int amount);
    void modifyHunger(int amount);
    void modifyHappiness(int amount);
    void modifyHygiene(int amount);
    void addMoney(int amount);
    bool spendMoney(int amount);

    void update(int deltaSeconds) override;
    std::string getDescription() const override;
    bool isDead() const;

    void addLog(const std::string& message);
    Inventory<std::string>& getActivityLog();
};


#endif //DREAM_APARTMENT_SIMULATOR_RESIDENT_H