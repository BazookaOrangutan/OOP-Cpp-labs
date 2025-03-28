#pragma once
#include <iostream>

class Weapon
{
private:
    std::string name;
    int attack;

public:
    Weapon(const std::string& n, int a);

    Weapon operator+(const Weapon& other) const;

    bool operator>(const Weapon& other) const;

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);

};

