#include "Monster.h"
#include "Character.h"
#include <iostream>
#include <stdexcept>

Monster::Monster(const std::string& name, int hp, int attack, int defense)
    : name(name), hp(hp), attackPower(attack), defense(defense) {}

void Monster::attack(Character& character) {
    character.takeDamage(attackPower);
}

void Monster::showInfo() const {
    std::cout << "Monster: " << name << ", HP: " << hp << "\n";
}

void Monster::takeDamage(int damage) {
    int dmg = damage - defense;
    hp -= (dmg > 0 ? dmg : 0);
    if (hp < 0) throw std::runtime_error(name + " has died!");
}

int Monster::getHP() const {
    return hp;
}

std::string Monster::getName() const {
    return name;
}

int Monster::getAttack() const { return attackPower; }
int Monster::getDefense() const { return defense; }
