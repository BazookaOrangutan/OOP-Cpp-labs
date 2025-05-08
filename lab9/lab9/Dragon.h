#pragma once
#include "Monster.h"

class Dragon : public Monster {
public:
    Dragon();
    Dragon(int hp, int atk, int def);
    std::unique_ptr<Monster> clone(int boost = 0) const override;
};

