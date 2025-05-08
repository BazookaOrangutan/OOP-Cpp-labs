#pragma once
#include "Monster.h"

class Goblin : public Monster {
public:
    Goblin();
    Goblin(int hp, int atk, int def);
    std::unique_ptr<Monster> clone(int boost = 0) const override;
};

