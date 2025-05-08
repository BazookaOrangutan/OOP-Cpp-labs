#include "Character.h"
#include "Monster.h"
#include <iostream>
#include <stdexcept>

Character::Character(const std::string& name)
    : name(name), hp(100), attackPower(20), defense(10), level(1), experience(0) {}

Character::Character(const std::string& name, int hp, int attack, int defense, int level, int exp)
    : name(name), hp(hp), attackPower(attack), defense(defense), level(level), experience(exp) {}

std::string Character::getName() const { return name; }
int Character::getAttack() const { return attackPower; }
int Character::getDefense() const { return defense; }
int Character::getLevel() const { return level; }
int Character::getExperience() const { return experience; }


void Character::attack(Monster& monster) {
    monster.takeDamage(attackPower);
}

void Character::heal(int amount) {
    hp += amount;
    std::cout << name << " heals for " << amount << " HP.\n";
}

Character Character::getDefaultCharacter(const std::string& name) {
    return Character(name, 100, 20, 10, 1, 0);
}

void Character::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        level++;
        experience = 0;
        attackPower += 5;
        defense += 3;
        hp += 20;
        std::cout << name << " leveled up to " << level << "! Stats increased.\n";
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

void Character::buffAttack(int amount) {
    attackPower += amount;
}

void Character::buffDefense(int amount) {
    defense += amount;
}
