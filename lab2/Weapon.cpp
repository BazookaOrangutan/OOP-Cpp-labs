#include "Weapon.h"

Weapon::Weapon(const std::string& n, int a, int w) : name(n), attack(a), weight(w)
{
	std::cout << "Weapon " << name << " created!\n";
}

void Weapon::displayInfo() const
{
	std::cout << "Name: " << name << ", Weight: " << weight
		<< ", Attack: " << attack << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << name << " destroyed!\n";
}


