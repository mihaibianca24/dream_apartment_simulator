//
// Created by Bianca Mihai on 20.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_ROOM_H
#define DREAM_APARTMENT_SIMULATOR_ROOM_H
#include <vector>
#include <memory>
#include "Item.h"

class Resident;

class Room : public Entity {
private:
    std::vector<std::unique_ptr<Item>> slots;
    int maxSlots;
public:
    Room(const std::string& name, int maxSlots);
    Room(const Room&) = delete;
    Room& operator=(const Room&) = delete;
    virtual ~Room() = default;

    std::string getRoomName() const;
    int getMaxSlots() const;
    int getOccupiedSlots() const;

    bool addItem(std::unique_ptr<Item> item);
    std::unique_ptr<Item> removeItem(const std::string& itemName);
    void applyAllEffects(Resident& resident);
    int getComfortScore() const;

    void update(int deltaSeconds) override;
    std::string getDescription() const override;

    const std::vector<std::unique_ptr<Item>>& getSlots() const;
};

#endif //DREAM_APARTMENT_SIMULATOR_ROOM_H