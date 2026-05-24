#include "GameEngine.h"
#include "ConsoleUI.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your character's name: ";
    std::string name;
    std::getline(std::cin, name);
    if (name.empty()) name = "Alex";
    // demonstrezi ca e aceeasi instanta
    Shop& s1 = Shop::getInstance();
    Shop& s2 = Shop::getInstance();
    // s1 si s2 sunt aceeasi instanta
    GameEngine engine(name, "Dream Apartment");
    ConsoleUI ui(engine);
    ui.run();
    return 0;
}