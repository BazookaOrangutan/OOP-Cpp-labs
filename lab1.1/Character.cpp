#include "Character.h"

Character::Character(const std::string& n, int h, int a, int d, int mh) : name(n), health(h), attack(a), defense(d), maxHealth(mh) {}

int Character::getHealth() const
{
	return health;
}

void Character::displayInfo() const
{
	std::cout << "Name: " << name << ", HP: " << health
		<< ", Attack: " << attack << ", Defense: " << defense << std::endl;
}

void Character::attackEnemy(Character& enemy)
{
    int damage = attack - enemy.defense;
    if (damage > 0) {
        enemy.health -= damage;
        std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
    }
    else {
        std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
    }
}

void Character::heal(int amount)
{
    health = (health + amount > maxHealth) ? maxHealth : health + amount;
    std::cout << name << " healing " << amount << " HP " << std::endl;
}

void Character::takeDamage(int amount)
{
    health = (health - amount < 0) ? 0 : health - amount;
    std::cout << name << " take " << amount << " damage " << std::endl;
}

