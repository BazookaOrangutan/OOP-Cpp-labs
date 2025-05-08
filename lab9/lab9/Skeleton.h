#pragma once

#include "Monster.h"

class Skeleton : public Monster {
public:
    Skeleton();
    Skeleton(int hp, int atk, int def);
    std::unique_ptr<Monster> clone(int boost = 0) const override;
};
