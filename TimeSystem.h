//
// Created by Bianca Mihai on 21.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_TIMESYSTEM_H
#define DREAM_APARTMENT_SIMULATOR_TIMESYSTEM_H
#include <thread>
#include <atomic>
#include <functional>

class TimeSystem {
private:
    std::thread gameThread;
    std::atomic<bool> running;
    std::function<void(int)> onTick;
    int tickIntervalMs;
public:
    explicit TimeSystem(std::function<void(int)> onTick, int tickIntervalMs = 1000);
    ~TimeSystem();

    void start();
    void stop();
    bool isRunning() const;

private:
    void run();
};
#endif //DREAM_APARTMENT_SIMULATOR_TIMESYSTEM_H