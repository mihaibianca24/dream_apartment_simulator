//
// Created by Bianca Mihai on 21.05.2026.
//

#include "EventSystem.h"
#include <algorithm>

EventSystem::EventSystem() : tickCounter(0) {}

void EventSystem::addListener(IEventListener* listener) {
    listeners.push_back(listener);
}

void EventSystem::removeListener(IEventListener* listener) {
    listeners.erase(
        std::remove(listeners.begin(), listeners.end(), listener),
        listeners.end()
    );
}

void EventSystem::notify(const std::string& eventName,
                         const std::string& message) {
    for (auto* listener : listeners) {
        listener->onEvent(eventName, message);
    }
}

void EventSystem::update(Resident& resident, int deltaSeconds) {
    tickCounter += deltaSeconds;

    if (tickCounter >= 30) {
        tickCounter = 0;
        int roll = std::rand() % 4;
        switch (roll) {
            case 0:
                resident.modifyHappiness(-10);
                notify("BAD_NEWS", "You received bad news. -10 happiness");
                break;
            case 1:
                resident.addMoney(50);
                notify("BONUS", "You found $50 on the street!");
                break;
            case 2:
                resident.modifyEnergy(-15);
                notify("POWER_OUT", "Power outage! -15 energy");
                break;
            case 3:
                resident.modifyHappiness(+15);
                notify("VISITOR", "A friend visited! +15 happiness");
                break;
        }
    }
}
