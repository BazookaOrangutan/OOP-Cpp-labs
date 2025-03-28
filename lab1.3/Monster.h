#pragma once
#include "Entity.h"

class Monster : public Entity
{
public:
    Monster(const std::string& n, int h, int p, int d);

    // Переопределение метода attack
    void attack(Entity& target) override;

    // Переопределение метода displayInfo
    void displayInfo() const override;

};

