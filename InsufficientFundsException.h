//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_INSUFFICIENTFUNDSEXCEPTION_H
#define DREAM_APARTMENT_SIMULATOR_INSUFFICIENTFUNDSEXCEPTION_H
#include <stdexcept>
#include <string>

class InsufficientFundsException : public std::runtime_error {
public:
    InsufficientFundsException(int available, int required)
        : std::runtime_error("Insufficient funds: have " +
          std::to_string(available) + ", need " +
          std::to_string(required)) {}
};
#endif//DREAM_APARTMENT_SIMULATOR_INSUFFICIENTFUNDSEXCEPTION_H