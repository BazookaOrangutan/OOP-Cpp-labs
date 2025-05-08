#pragma once
#include <string>

class Monster {
protected:
    std::string name;
    int hp, attackPower, defense;

public:
    Monster(const std::string& name, int hp, int attack, int defense);
    virtual ~Monster() = default;
    virtual void attack(class Character& character);
    virtual void showInfo() const;
    virtual void takeDamage(int damage);
    int getHP() const;
    std::string getName() const;
};
