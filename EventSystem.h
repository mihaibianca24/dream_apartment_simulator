//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_EVENTSYSTEM_H
#define DREAM_APARTMENT_SIMULATOR_EVENTSYSTEM_H
#include <vector>
#include <string>
#include "IEventListener.h"
#include "Resident.h"

class EventSystem {
private:
    std::vector<IEventListener*> listeners;
    int tickCounter;
public:
    EventSystem();

    void addListener(IEventListener* listener);
    void removeListener(IEventListener* listener);
    void notify(const std::string& eventName,
                const std::string& message);
    void update(Resident& resident, int deltaSeconds);
};
#endif //DREAM_APARTMENT_SIMULATOR_GAMEENGINE_H