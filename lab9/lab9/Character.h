#pragma once

#include <string>

class Character {
private:
    std::string name;
    int hp, attackPower, defense, level, experience;

public:
    Character(const std::string& name);
    Character(const std::string& name, int hp, int attack, int defense, int level, int exp);

    void attack(class Monster& monster);
    void heal(int amount);
    void gainExperience(int exp);
    void showInfo() const;
    static Character getDefaultCharacter(const std::string& name);

    std::string getName() const;
    int getAttack() const;
    int getDefense() const;
    int getLevel() const;
    int getExperience() const;
    int getHP() const;
    void takeDamage(int damage);

    void buffAttack(int amount);
    void buffDefense(int amount);

};

