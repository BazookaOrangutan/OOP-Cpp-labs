#include "Weapon.h"

Weapon::Weapon(const std::string& n, int a) : name(n), attack(a)
{
}

Weapon Weapon::operator+(const Weapon& other) const
{
    return Weapon(name + other.name, attack + other.attack);
}

bool Weapon::operator>(const Weapon& other) const
{
    return attack > other.attack;
}

std::ostream& operator<<(std::ostream& os, const Weapon& weapon)
{
    os << "Weapon: " << weapon.name << ", Attack: " << weapon.attack;
    return os;
}
