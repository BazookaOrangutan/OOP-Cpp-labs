#include "Player.h"

Player::Player(const std::string& n, int h, int exp) : Entity(n, h), experience(exp) {}

void Player::displayInfo() const
{
	Entity::displayInfo();
	std::cout << "Experience: " << experience << std::endl;
}
