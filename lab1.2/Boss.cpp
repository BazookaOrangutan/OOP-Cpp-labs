#include "Boss.h"

Boss::Boss(const std::string& n, int h, const std::string& t, const std::string& sa) : Enemy(n, h, t) , specialAbility(sa) {}

void Boss::displayInfo() const
{
	Enemy::displayInfo();
	std::cout << "Special ability: " << specialAbility << std::endl;
}
