#include "Skeleton.h"

Skeleton::Skeleton() : Monster("Skeleton", 40, 15, 0) {}
Skeleton::Skeleton(int hp, int atk, int def) : Monster("Skeleton", hp, atk, def) {}

std::unique_ptr<Monster> Skeleton::clone(int boost) const {
    return std::make_unique<Skeleton>(40 + boost * 10, attackPower + boost * 3, defense + boost * 2);
}
