#include "Enemy.h"

Enemy::Enemy(const std::string& n, int h, const std::string& t) : Entity(n, h), type(t)
{
	std::cout << "Create " << n << " enemy" << std::endl;
}

void Enemy::displayInfo() const
{
	Entity::displayInfo();
	std::cout << "Type: " << type << std::endl;

}

Enemy::~Enemy()
{
	std::cout << "Enemy " << name << " was destroyed" << std::endl;
}
