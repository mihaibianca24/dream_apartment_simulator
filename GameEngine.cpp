//
// Created by Bianca Mihai on 21.05.2026.
//

#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(const std::string& residentName,
                       const std::string& apartmentName)
    : resident(residentName),
      apartment(apartmentName, resident),
      shop(Shop::getInstance()),
      isRunning(false),
      dayCount(1),
      secondCounter(0) {

    timeSystem = std::make_unique<TimeSystem>(
        [this](int delta) { tick(delta); }, 1000
    );

    eventSystem = std::make_unique<EventSystem>();
    eventSystem->addListener(this);
}

void GameEngine::start() {
    isRunning = true;
    std::cout << "Game started! Day " << dayCount << "\n";
    timeSystem->start();
}

void GameEngine::stop() {
    isRunning = false;
    timeSystem->stop();
    std::cout << "Game stopped.\n";
}

void GameEngine::tick(int deltaSeconds) {
    if (!isRunning) return;

    resident.update(deltaSeconds);
    apartment.update(deltaSeconds);
    eventSystem->update(resident, deltaSeconds);

    secondCounter += deltaSeconds;

    // 60 secunde reale = 1 zi in joc
    if (secondCounter >= 60) {
        secondCounter = 0;
        dayCount++;
        std::cout << "=== Day " << dayCount << " ===\n";
    }

    if (resident.isDead()) {
        isRunning = false;
        std::cout << "GAME OVER! " << resident.getName()
                  << " ran out of energy on day "
                << dayCount << "\n";
        timeSystem->stop();
    }
}

void GameEngine::onEvent(const std::string& eventName,
                         const std::string& eventMessage) {
    std::cout << "[EVENT] " << eventName << ": "
              << eventMessage << "\n";
}

Resident& GameEngine::getResident() { return resident; }
Apartment& GameEngine::getApartment() { return apartment; }
Shop& GameEngine::getShop() { return shop; }

bool GameEngine::getIsRunning() const { return isRunning; }
int GameEngine::getDayCount() const { return dayCount; }