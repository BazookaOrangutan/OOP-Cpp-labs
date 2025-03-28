#pragma once
#include <iostream>

class Character
{
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    // Конструктор
    Character(const std::string& n, int h, int a, int d);

    void displayInfo() const;

    // Деструктор
    ~Character();

   

};

