#pragma once
#include "Entity.h"

class Character : public Entity {
public:
    Character(const std::string& n, int h, int p, int d);

    void attack(Entity& target) override;

    void heal(int amount) override;

    void displayInfo() const override;
};

