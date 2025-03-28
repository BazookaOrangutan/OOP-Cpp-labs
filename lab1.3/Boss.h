#pragma once
#include "Monster.h"

class Boss : public Monster
{
public:
	Boss(const std::string& n, int h, int p, int d);

	void attack(Entity& target) override;

	void displayInfo() const override;
};

