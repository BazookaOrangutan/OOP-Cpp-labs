#pragma once
#include <iostream>

class Weapon
{
private:
    std::string name;
    int attack;
    int weight;

public:
    // Конструктор
    Weapon(const std::string& n, int a, int w);

    void displayInfo() const;

    // Деструктор
    ~Weapon();

};

