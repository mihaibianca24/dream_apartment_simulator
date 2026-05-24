#include "GameEngine.h"
#include "ConsoleUI.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your character's name: ";
    std::string name;
    std::getline(std::cin, name);
    if (name.empty()) name = "Alex";
    Shop& s1 = Shop::getInstance();
    Shop& s2 = Shop::getInstance();
    GameEngine engine(name, "Dream Apartment");
    ConsoleUI ui(engine);
    ui.run();
    return 0;
}