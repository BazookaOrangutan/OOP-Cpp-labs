#pragma once

#include <iostream>
#include <string>

class Character {
    std::string name;  
    int health;        
    int attack;        
    int defense;       
    int maxHealth;

public:
    Character(const std::string& n, int h, int a, int d, int mh);

    int getHealth() const;

    void displayInfo() const;

    void attackEnemy(Character& enemy);
   
    void heal(int amount);

    void takeDamage(int amount);
};

