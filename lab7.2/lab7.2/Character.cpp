#include "Character.h"

Character::Character(const std::string& n, int h, int a, int d) : name(n), health(h), attack(a), defense(d)
{
    std::cout << "Character " << name << " created!\n";
}

std::string Character::getName()
{
    return name;
}

int Character::getHealth()
{
    return health;
}

int Character::getAttack()
{
    return attack;
}

int Character::getDefense()
{
    return defense;
}

void Character::setHealth(int h)
{
    health = h;
}


void Character::displayInfo() const
{
    std::cout << "Name: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense << std::endl;

}


