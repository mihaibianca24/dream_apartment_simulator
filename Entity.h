//
// Created by Bianca Mihai on 19.05.2026.
//

#ifndef DREAM_APARTMENT_SIMULATOR_ENTITY_H
#define DREAM_APARTMENT_SIMULATOR_ENTITY_H
#include<string>


class Entity {
private:
    std::string name;
public:
    Entity();
    Entity(const std::string &name);
    virtual ~Entity();
    std::string getName() const;
    virtual void update(int deltaSeconds)=0;
    virtual std::string getDescription() const=0;
};


#endif //DREAM_APARTMENT_SIMULATOR_ENTITY_H