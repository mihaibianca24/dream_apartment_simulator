#include "GameEngine.h"
#include "ConsoleUI.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "╔══════════════════════════════════════════╗\n";
    std::cout << "║       DREAM APARTMENT SIMULATOR          ║\n";
    std::cout << "╚══════════════════════════════════════════╝\n\n";
    std::cout << "  Enter your character's name: ";

    std::string name;
    std::getline(std::cin, name);
    if (name.empty()) name = "Alex";

    GameEngine engine(name, "Dream Apartment");
    ConsoleUI ui(engine);
    ui.run();
    return 0;
}