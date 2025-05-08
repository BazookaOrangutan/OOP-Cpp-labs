#pragma once

#include <string>
#include "Inventory.h"

class Character {
private:
    std::string name;
    int hp, attackPower, defense, level, experience;
    Inventory inventory;

public:
    Character(const std::string& name);
    void attack(class Monster& monster);
    void heal(int amount);
    void gainExperience(int exp);
    void showInfo() const;

    int getHP() const;
    void takeDamage(int damage);
    Inventory& getInventory();
};

