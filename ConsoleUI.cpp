//
// Created by Bianca Mihai on 23.05.2026.
//

#include "ConsoleUI.h"
#include "GameEngine.h"
#include "InsufficientFundsException.h"
#include "SlotOccupiedException.h"
#include <iostream>
#include <string>
#include <limits>
#include <thread>
#include <chrono>

ConsoleUI::ConsoleUI(GameEngine& engine)
    : engine(engine), running(true) {}

std::string ConsoleUI::statBar(int val) {
    std::string b = "[";
    int filled = val / 10;
    for (int i = 0; i < 10; i++)
        b += (i < filled ? "█" : "░");
    b += "] " + std::to_string(val);
    return b;
}

void ConsoleUI::renderIntro() {
    system("clear");
    std::cout << "╔══════════════════════════════════════════╗\n";
    std::cout << "║       DREAM APARTMENT SIMULATOR          ║\n";
    std::cout << "╚══════════════════════════════════════════╝\n\n";
    std::cout << "  Welcome!\n\n";
    std::cout << "  Your goal is to build your dream apartment.\n\n";
    std::cout << "  HOW IT WORKS:\n";
    std::cout << "  - Buy items from the shop\n";
    std::cout << "  - Use them to maintain your stats\n";
    std::cout << "  - Earn money by working at Desk or Computer\n";
    std::cout << "  - Raise your Dream Level to 100%\n\n";
    std::cout << "  WARNING:\n";
    std::cout << "  - Stats decrease automatically over time\n";
    std::cout << "  - If Energy reaches 0 = Game Over!\n\n";
}

void ConsoleUI::renderGameOver() {
    system("clear");
    std::cout << "╔══════════════════════════════════════════╗\n";
    if (!engine.getIsRunning() && engine.getResident().isDead()) {
        std::cout << "║              GAME OVER                   ║\n";
        std::cout << "╚══════════════════════════════════════════╝\n\n";
        std::cout << "  " << engine.getResident().getName()
                  << " ran out of energy on day "
                  << engine.getDayCount() << ".\n\n";
    } else {
        std::cout << "║           YOU EXITED THE GAME            ║\n";
        std::cout << "╚══════════════════════════════════════════╝\n\n";
        std::cout << "  Goodbye, " << engine.getResident().getName() << "!\n\n";
    }

    std::cout << "  Dream Level reached : "
              << engine.getApartment().getDreamLevel() << "%\n";
    std::cout << "  Days survived       : "
              << engine.getDayCount() << "\n\n";
    std::cout << "  Thanks for playing!\n\n";
}

void ConsoleUI::renderWarnings() {
    Resident& r = engine.getResident();
    bool hasWarning = false;

    if (r.getEnergy() <= 20) {
        std::cout << "  ⚠  WARNING: Critical energy ("
                  << r.getEnergy() << ")! Go to sleep!\n";
        hasWarning = true;
    }
    if (r.getHunger() <= 20) {
        std::cout << "  ⚠  WARNING: Critical hunger ("
                  << r.getHunger() << ")! Eat something!\n";
        hasWarning = true;
    }
    if (r.getHappiness() <= 20) {
        std::cout << "  ⚠  WARNING: Low happiness ("
                  << r.getHappiness() << ")! Relax!\n";
        hasWarning = true;
    }
    if (r.getHygiene() <= 20) {
        std::cout << "  ⚠  WARNING: Low hygiene ("
                  << r.getHygiene() << ")! Take a shower!\n";
        hasWarning = true;
    }
    if (hasWarning)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void ConsoleUI::run() {
    renderIntro();
    engine.start();
    while (running && engine.getIsRunning()) {
        render();
        renderWarnings();
        handleInput();
    }
    engine.stop();
    renderGameOver();
}

void ConsoleUI::render() {
    system("clear");

    std::cout << "╔══════════════════════════════════════════╗\n";
    std::cout << "║       DREAM APARTMENT SIMULATOR          ║\n";
    std::cout << "╚══════════════════════════════════════════╝\n\n";

    Resident& r = engine.getResident();
    std::cout << "  Resident : " << r.getName()
              << "  |  Day: " << engine.getDayCount()
              << "  |  Money: $" << r.getMoney() << "\n\n";

    int dl = engine.getApartment().getDreamLevel();
    std::cout << "  Dream Level: [";
    int filled = dl / 5;
    for (int i = 0; i < 20; i++)
        std::cout << (i < filled ? "█" : "░");
    std::cout << "] " << dl << "%\n\n";

    renderStats();
    renderApartment();
    renderMenu();
}

void ConsoleUI::renderStats() {
    std::cout << "── STATS ────────────────────────────────────\n";
    Resident& r = engine.getResident();
    std::cout << "  Energy    " << statBar(r.getEnergy())    << "\n";
    std::cout << "  Hunger    " << statBar(r.getHunger())    << "\n";
    std::cout << "  Happiness " << statBar(r.getHappiness()) << "\n";
    std::cout << "  Hygiene   " << statBar(r.getHygiene())   << "\n\n";
}

void ConsoleUI::renderApartment() {
    std::cout << "── APARTMENT ────────────────────────────────\n";
    std::cout << engine.getApartment().getDescription() << "\n";
}

void ConsoleUI::renderMenu() {
    std::cout << "── MENU ─────────────────────────────────────\n";
    std::cout << "  1. Use items         (apply effects from a room)\n";
    std::cout << "  2. Buy from shop     (purchase new items)\n";
    std::cout << "  3. View shop         (full catalog with prices)\n";
    std::cout << "  4. Activity log      (your action history)\n";
    std::cout << "  5. Quit\n";
    std::cout << "─────────────────────────────────────────────\n";
    std::cout << "  Choice: ";
}

void ConsoleUI::handleInput() {
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
        case 1: menuUseItem();     break;
        case 2: menuBuyFromShop(); break;
        case 3: menuViewShop();    break;
        case 4: menuViewLog();     break;
        case 5: running = false;   break;
        default:
            std::cout << "  Invalid choice. Try again.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void ConsoleUI::menuUseItem() {
    system("clear");
    renderStatusBar();
    std::cout << "── USE ITEMS ────────────────────────────────\n\n";
    std::cout << "  Which room?\n";
    std::cout << "  1. Bedroom\n";
    std::cout << "  2. Living Room\n";
    std::cout << "  3. Bathroom\n";
    std::cout << "  Choice: ";

    int roomChoice;
    std::cin >> roomChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Room* room = nullptr;
    if (roomChoice == 1)      room = &engine.getApartment().getBedroom();
    else if (roomChoice == 2) room = &engine.getApartment().getLivingRoom();
    else if (roomChoice == 3) room = &engine.getApartment().getBathroom();
    else {
        std::cout << "  Invalid room.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    const auto& slots = room->getSlots();
    if (slots.empty()) {
        std::cout << "\n  This room is empty! Buy some items first.\n";
        std::cout << "\n  Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "\n  Items in " << room->getRoomName() << ":\n";
    for (int i = 0; i < (int)slots.size(); i++) {
        if (slots[i] != nullptr) {
            std::cout << "  " << (i + 1) << ". "
                      << slots[i]->getDescription() << "\n";
        }
    }

    std::cout << "\n  Which item to use? (0 to cancel): ";
    int itemChoice;
    if (!(std::cin >> itemChoice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Invalid input.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (itemChoice == 0) return;
    if (itemChoice < 1 || itemChoice > (int)slots.size()) {
        std::cout << "  Invalid choice.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    Item* item = slots[itemChoice - 1].get();
    if (item == nullptr) {
        std::cout << "  No item in that slot.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    Resident& r = engine.getResident();
    int energyBefore    = r.getEnergy();
    int hungerBefore    = r.getHunger();
    int happinessBefore = r.getHappiness();
    int hygieneBefore   = r.getHygiene();
    int moneyBefore     = r.getMoney();

    try {
        item->applyEffect(r);
        r.addLog("Used " + item->getName());

        std::cout << "\n  Used " << item->getName() << "!\n";
        std::cout << "  Effects applied:\n";

        auto printDiff = [](const std::string& label, int before, int after) {
            if (after != before) {
                int diff = after - before;
                std::cout << "  " << label << ": "
                          << before << " -> " << after
                          << " (" << (diff > 0 ? "+" : "") << diff << ")\n";
            }
        };

        printDiff("Energy",    energyBefore,    r.getEnergy());
        printDiff("Hunger",    hungerBefore,    r.getHunger());
        printDiff("Happiness", happinessBefore, r.getHappiness());
        printDiff("Hygiene",   hygieneBefore,   r.getHygiene());

        if (r.getMoney() != moneyBefore) {
            int diff = r.getMoney() - moneyBefore;
            std::cout << "  Money: $" << moneyBefore
                      << " -> $" << r.getMoney()
                      << " (" << (diff > 0 ? "+" : "") << diff << ")\n";
        }

    } catch (const std::exception& e) {
        std::cout << "  Error: " << e.what() << "\n";
    }

    std::cout << "\n  Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void ConsoleUI::menuBuyFromShop() {
    system("clear");
    std::cout << "── SHOP ─────────────────────────────────────\n\n";
    engine.getShop().printCatalog();
    std::cout << "\n  Available money: $"
              << engine.getResident().getMoney() << "\n\n";
    std::cout << "  Enter item name (or Enter to cancel): ";

    std::string itemName;
    std::getline(std::cin, itemName);
    if (itemName.empty()) return;

    std::cout << "\n  Which room?\n";
    std::cout << "  1. Bedroom\n";
    std::cout << "  2. Living Room\n";
    std::cout << "  3. Bathroom\n";
    std::cout << "  Choice: ";

    int roomChoice;
    std::cin >> roomChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Room* room = nullptr;
    if (roomChoice == 1)      room = &engine.getApartment().getBedroom();
    else if (roomChoice == 2) room = &engine.getApartment().getLivingRoom();
    else if (roomChoice == 3) room = &engine.getApartment().getBathroom();
    else {
        std::cout << "  Invalid room.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    try {
        auto item = engine.getShop().buyItem(itemName, engine.getResident());
        room->addItem(std::move(item));
        std::cout << "\n  " << itemName << " bought and placed successfully!\n";
        std::cout << "  Remaining money: $"
                  << engine.getResident().getMoney() << "\n";
    } catch (const InsufficientFundsException& e) {
        std::cout << "\n  Not enough money! " << e.what() << "\n";
    } catch (const SlotOccupiedException& e) {
        std::cout << "\n  Room is full! " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "\n  Error: " << e.what() << "\n";
    }

    std::cout << "\n  Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleUI::menuViewShop() {
    system("clear");
    std::cout << "── SHOP ─────────────────────────────────────\n\n";
    engine.getShop().printCatalog();
    std::cout << "\n  Available money: $"
              << engine.getResident().getMoney() << "\n";
    std::cout << "\n  Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleUI::menuViewLog() {
    system("clear");
    std::cout << "── ACTIVITY LOG ─────────────────────────────\n\n";
    auto& log = engine.getResident().getActivityLog();
    if (log.isEmpty()) {
        std::cout << "  No activity yet.\n";
    } else {
        for (int i = 0; i < log.getSize(); i++)
            std::cout << "  - " << log.get(i) << "\n";
    }
    std::cout << "\n  Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleUI::renderStatusBar() {
    Resident& r = engine.getResident();
    std::cout << "─────────────────────────────────────────────\n";
    std::cout << "  Energy " << statBar(r.getEnergy())
              << "  Hunger " << statBar(r.getHunger()) << "\n";
    std::cout << "  Happin " << statBar(r.getHappiness())
              << "  Hygien " << statBar(r.getHygiene()) << "\n";
    std::cout << "  Money: $" << r.getMoney()
              << "  |  Day: " << engine.getDayCount()
              << "  |  Dream: " << engine.getApartment().getDreamLevel() << "%\n";
    std::cout << "─────────────────────────────────────────────\n\n";
}