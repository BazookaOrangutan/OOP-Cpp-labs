#include "Monster.h"

Monster::Monster(const std::string& n, int h, int a, int d) : name(n), health(h), attack(a), defense(d) {
    std::cout << "Monster " << name << " created!\n";
}

std::string Monster::getName()
{
    return name;
}

int Monster::getHealth()
{
    return health;
}

int Monster::getAttack()
{
    return attack;
}

int Monster::getDefense()
{
    return defense;
}

void Monster::setHealth(int h)
{
    health = h;
}

void Monster::displayInfo() const
{
    std::cout << "Name: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense << std::endl;
}



