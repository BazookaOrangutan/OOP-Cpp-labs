#include "Entity.h"

Entity::Entity(const std::string& n, int h, int p, int d) : name(n), health(h), power(p), defense(d) 
{
}

int Entity::getDefense() const
{
    return defense;
}

int Entity::getHealth() const
{
    return health;
}

void Entity::setHealth(int h)
{
    health = h;
}

std::string Entity::getName()
{
    return name;
}

void Entity::attack(Entity& target)
{
    int damage = power - target.defense;
    if (damage > 0) {
        target.health -= damage;
        std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
    }
    else {
        std::cout << name << " attacks " << target.name << ", but it has no effect!\n";
    }
}

void Entity::heal(int amount)
{
    std::cout << "This entity cant heal" << std::endl;
}

void Entity::displayInfo() const
{
    std::cout << "Name: " << name << ", HP: " << health
        << ", Power: " << power << ", Defense: " << defense << std::endl;

}

Entity::~Entity()
{
}



