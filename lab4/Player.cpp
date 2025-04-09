#include "Player.h"

Player::Player(const std::string& n, int h, int exp) : Entity(n, h), experience(exp)
{
	std::cout << "Player " << n << " created" << std::endl;
}

void Player::displayInfo() const
{
	Entity::displayInfo();
	std::cout << "Experience: " << experience << std::endl;
}

Player::~Player()
{
	std::cout << "Player " << name << " was destroyed" << std::endl;
}

