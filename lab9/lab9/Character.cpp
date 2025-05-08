#include "Character.h"
#include "Monster.h"
#include <iostream>
#include <stdexcept>

Character::Character(const std::string& name)
    : name(name), hp(100), attackPower(20), defense(10), level(1), experience(0) {}

void Character::attack(Monster& monster) {
    monster.takeDamage(attackPower);
}

void Character::heal(int amount) {
    hp += amount;
    std::cout << name << " heals for " << amount << " HP.\n";
}

void Character::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        level++;
        experience = 0;
        std::cout << name << " leveled up to " << level << "!\n";
    }
}

void Character::showInfo() const {
    std::cout << "Name: " << name << ", HP: " << hp << ", Attack: " << attackPower
        << ", Defense: " << defense << ", Level: " << level << ", XP: " << experience << "\n";
}

int Character::getHP() const {
    return hp;
}

void Character::takeDamage(int damage) {
    int dmg = damage - defense;
    hp -= (dmg > 0 ? dmg : 0);
    if (hp < 0) throw std::runtime_error(name + " has died!");
}

Inventory& Character::getInventory() {
    return inventory;
}
