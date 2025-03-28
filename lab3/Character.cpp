#include "Character.h"

Character::Character(const std::string& n, int h, int a, int d) : name(n), health(h), attack(a), defense(d)
{
}

bool Character::operator==(const Character& other) const
{
	return name == other.name && health == other.health;
}

std::ostream& operator<<(std::ostream& os, const Character& character)
{
	os << "Character: " << character.name << ", HP: " << character.health
		<< ", Attack: " << character.attack << ", Defense: " << character.defense;
	return os;

}
