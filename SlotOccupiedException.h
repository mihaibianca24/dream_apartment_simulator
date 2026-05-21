//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_SLOTOCCUPIEDEXCEPTION_H
#define DREAM_APARTMENT_SIMULATOR_SLOTOCCUPIEDEXCEPTION_H
#include <stdexcept>
#include <string>

class SlotOccupiedException : public std::runtime_error {
public:
    explicit SlotOccupiedException(const std::string& roomName)
        : std::runtime_error("No available slots in room: " + roomName) {}
};
#endif//DREAM_APARTMENT_SIMULATOR_SLOTOCCUPIEDEXCEPTION_H