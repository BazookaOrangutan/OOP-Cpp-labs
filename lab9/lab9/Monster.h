#pragma once
#include <string>
#include <iostream>

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
    virtual std::unique_ptr<Monster> clone(int boost = 0) const = 0;
    int getHP() const;
    std::string getName() const;
    int getAttack() const;
    int getDefense() const;

};
