//
// Created by Bianca Mihai on 23.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_CONSOLEUI_H
#define DREAM_APARTMENT_SIMULATOR_CONSOLEUI_H
#include <iostream>

class GameEngine;
class ConsoleUI {
    private:
    GameEngine& engine;
    bool running;
    void renderStatusBar();
public:
    explicit ConsoleUI(GameEngine& engine);

    void run();
    void render();
    void handleInput();

private:
    void renderStats();
    void renderApartment();
    void renderMenu();
    void renderEvent();

    void menuUseItem();
    void menuBuyFromShop();
    void menuViewShop();
    void menuViewLog();
    void renderIntro();
    void renderGameOver();
    void renderWarnings();
    std::string statBar(int val);
};


#endif //DREAM_APARTMENT_SIMULATOR_CONSOLEUI_H