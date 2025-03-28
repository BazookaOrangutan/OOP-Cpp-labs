#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
	std::string specialAbility;

public:

	Boss(const std::string& n, int h, const std::string& t, const std::string& sa);

	void displayInfo() const override;
};

