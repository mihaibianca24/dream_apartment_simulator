# Dream Apartment Simulator

A C++ simulation game where you build and manage your dream apartment. Buy furniture, appliances, and decorations to improve your living space while keeping your resident happy and healthy.

## Gameplay

- **Buy items** from the shop to furnish your apartment
- **Use items** to restore your resident's stats (energy, hunger, happiness, hygiene)
- **Earn money** by working at the Desk or Computer
- **Raise your Dream Level** to 100% by furnishing all rooms and maintaining high stats
- **Random events** occur over time — some good, some bad
- Stats decrease automatically over time — if Energy reaches 0, it's **Game Over**!

## Features

- 3 rooms: Bedroom, Living Room, Bathroom
- 9 purchasable items across 3 categories: Furniture, Appliances, Decorations
- Real-time stats system running on a separate thread
- Interactive console menu
- Activity log tracking all your actions
- Random event system

## OOP Concepts Demonstrated

| Concept | Where |
|---|---|
| Inheritance (3 levels) | `Entity → Item → Furniture → Bed` |
| Polymorphism | `virtual applyEffect(Resident&)` in every Item |
| Abstraction | `Entity`, `Item`, `Furniture`, `Appliance`, `Decoration` are abstract |
| Encapsulation | All attributes private, accessed via getters/setters |
| Composition | `Apartment` contains `Room`, `Room` contains `Item` |
| Smart pointers | `unique_ptr<Item>` in Room slots, `unique_ptr<TimeSystem>` in GameEngine |
| Templates | `Inventory<T>` used as `Inventory<ShopEntry>` and `Inventory<std::string>` |
| Threads | `TimeSystem` runs on a separate `std::thread` |
| STL | `vector`, `string`, `function`, `map`, `algorithm` |
| Exceptions | `InsufficientFundsException`, `SlotOccupiedException` |
| Operator overloading | `operator<<` on `Entity` |

## Design Patterns

### 1. Factory Method — `ItemFactory`
Creates Item objects polymorphically based on a string type. Used in `Shop::buyItem()`.
```cpp
std::unique_ptr<Item> item = ItemFactory::create("Bed");
```

### 2. Observer — `EventSystem` + `IEventListener`
`EventSystem` notifies all registered listeners when a random event occurs.
`GameEngine` implements `IEventListener` and receives event notifications.
```cpp
eventSystem->addListener(this);  // GameEngine registers as listener
eventSystem->notify("VISITOR", "A friend visited! +15 happiness");
```

### 3. Singleton — `Shop`
Only one Shop instance exists throughout the game.
```cpp
Shop& shop = Shop::getInstance();
```

## Class Hierarchy

```
Entity (abstract)
├── Resident
│     energy, hunger, happiness, hygiene, money
│     Inventory<string> activityLog
│
├── Item (abstract)
│   ├── Furniture (abstract)
│   │   ├── Bed
│   │   ├── Sofa
│   │   ├── Fridge
│   │   └── Shower
│   ├── Appliance (abstract)
│   │   ├── Desk
│   │   ├── Computer
│   │   └── TV
│   └── Decoration (abstract)
│       ├── Plant
│       └── Painting
│
└── Room (abstract)
    ├── Bedroom
    ├── LivingRoom
    └── Bathroom

Apartment       — contains rooms + calculates Dream Level
Shop            — Singleton, catalog of items
ItemFactory     — Factory Method pattern
GameEngine      — coordinates all components
TimeSystem      — separate thread, emits tick every second
EventSystem     — Observer pattern, random events
ConsoleUI       — interactive console interface

Templates:
Inventory<T>    — generic collection, used with ShopEntry and string

Exceptions:
InsufficientFundsException  — thrown when player can't afford an item
SlotOccupiedException       — thrown when a room is full
```

## How to Build

### Requirements
- C++20 compatible compiler (GCC 10+, Clang 12+, MSVC 2019+)
- CMake 3.16+
- CLion (recommended) or any CMake-compatible IDE

### Build with CLion
1. Open the project folder in CLion
2. CLion will automatically detect `CMakeLists.txt`
3. Click **Build → Build Project**
4. Run with **Run → Run 'dream_apartment_simulator'**

## How to Play

1. Enter your character's name
2. Use the numbered menu to navigate:
   - **1. Use items** — select a room and use an item to restore stats
   - **2. Buy from shop** — purchase new items and place them in a room
   - **3. Activity log** — view your action history
   - **4. Quit** — exit the game
3. Stats decrease automatically over time — keep them above 0!
4. Earn money by using Desk ($30/use) or Computer ($60/use)
5. Fill your apartment with items to raise your Dream Level to 100%

## Project Structure

```
dream_apartment_simulator/
├── CMakeLists.txt
├── README.md
├── main.cpp
├── Entity.h / Entity.cpp
├── Item.h / Item.cpp
├── Resident.h / Resident.cpp
├── Inventory.h
├── Room.h / Room.cpp
├── Bedroom.h / Bedroom.cpp
├── LivingRoom.h / LivingRoom.cpp
├── Bathroom.h / Bathroom.cpp
├── Apartment.h / Apartment.cpp
├── Furniture.h / Furniture.cpp
├── Bed.h / Bed.cpp
├── Sofa.h / Sofa.cpp
├── Fridge.h / Fridge.cpp
├── Shower.h / Shower.cpp
├── Appliance.h / Appliance.cpp
├── Desk.h / Desk.cpp
├── Computer.h / Computer.cpp
├── TV.h / TV.cpp
├── Decoration.h / Decoration.cpp
├── Plant.h / Plant.cpp
├── Painting.h / Painting.cpp
├── Shop.h / Shop.cpp
├── ItemFactory.h / ItemFactory.cpp
├── GameEngine.h / GameEngine.cpp
├── TimeSystem.h / TimeSystem.cpp
├── EventSystem.h / EventSystem.cpp
├── IEventListener.h
├── InsufficientFundsException.h
├── SlotOccupiedException.h
└── ConsoleUI.h / ConsoleUI.cpp
```

## Author

Mihai Maria Bianca— OOP Project, 2026
