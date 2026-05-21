//
// Created by Bianca Mihai on 21.05.2026.
//

#include "TimeSystem.h"
#include <chrono>

TimeSystem::TimeSystem(std::function<void(int)> onTick, int tickIntervalMs)
    : onTick(onTick), tickIntervalMs(tickIntervalMs), running(false) {}

TimeSystem::~TimeSystem() {
    stop();
}

void TimeSystem::start() {
    running = true;
    gameThread = std::thread(&TimeSystem::run, this);
}

void TimeSystem::stop() {
    running = false;
    if (gameThread.joinable()) {
        gameThread.join();
    }
}

bool TimeSystem::isRunning() const {
    return running;
}

void TimeSystem::run() {
    while (running) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(tickIntervalMs)
        );
        if (running) {
            onTick(tickIntervalMs / 1000);
        }
    }
}