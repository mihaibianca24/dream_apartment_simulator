#include "Entity.h"
#include<string>
using namespace std;

Entity::Entity() {
    this->name="";
}

Entity::Entity(const std::string &name) {
    this->name=name;
}
std::string Entity::getName() const{
    return name;
}
Entity::~Entity() = default;