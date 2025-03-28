#include "Enemy.h"

Enemy::Enemy(const std::string& n, int h, const std::string& t) : Entity(n, h), type(t) {}

void Enemy::displayInfo() const
{
	Entity::displayInfo();
	std::cout << "Type: " << type << std::endl;

}


