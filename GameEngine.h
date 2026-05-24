//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_GAMEENGINE_H
#define DREAM_APARTMENT_SIMULATOR_GAMEENGINE_H
#include <string>
#include <memory>
#include "Resident.h"
#include "Apartment.h"
#include "Shop.h"
#include "TimeSystem.h"
#include "EventSystem.h"
#include "IEventListener.h"

class GameEngine : public IEventListener {
private:
    Resident resident;
    Apartment apartment;
    Shop& shop;
    std::unique_ptr<TimeSystem> timeSystem;
    std::unique_ptr<EventSystem> eventSystem;
    bool isRunning;
    int dayCount;
    int secondCounter;

public:
    GameEngine(const std::string& residentName,
               const std::string& apartmentName);

    void start();
    void stop();

    Resident& getResident();
    Apartment& getApartment();
    Shop& getShop();

    bool getIsRunning() const;
    int getDayCount() const;

    void tick(int deltaSeconds);

    void onEvent(const std::string& eventName,
                 const std::string& eventMessage) override;

    ~GameEngine() override = default;
};
#endif //DREAM_APARTMENT_SIMULATOR_GAMEENGINE_H