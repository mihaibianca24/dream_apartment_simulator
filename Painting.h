//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_PAINTING_H
#define DREAM_APARTMENT_SIMULATOR_PAINTING_H
#include "Decoration.h"

class Painting : public Decoration {
public:
    Painting(const std::string& name = "Painting", int cost = 100, int comfortBonus = 8, int happinessBonus = 8);
    Painting(const Painting& obj);
    Painting& operator=(const Painting& obj);
    ~Painting();

    void dailyEffect(Resident& resident) override;
    std::string getDescription() const override;
};

#endif //DREAM_APARTMENT_SIMULATOR_PAINTING_H