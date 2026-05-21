//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_IEVENTLISTENER_H
#define DREAM_APARTMENT_SIMULATOR_IEVENTLISTENER_H
#include <string>

class IEventListener {
public:
    virtual void onEvent(const std::string& eventName,
                        const std::string& eventMessage) = 0;
    virtual ~IEventListener() = default;
};
#endif //DREAM_APARTMENT_SIMULATOR_IEVENTLISTENER_H