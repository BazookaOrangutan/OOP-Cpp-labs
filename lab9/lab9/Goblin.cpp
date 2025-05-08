#include "Goblin.h"

Goblin::Goblin() : Monster("Goblin", 50, 10, 5) {}

Goblin::Goblin(int hp, int atk, int def) : Monster("Goblin", hp, atk, def) {}

std::unique_ptr<Monster> Goblin::clone(int boost) const {
    return std::make_unique<Goblin>(50 + boost * 10, attackPower + boost * 3, defense + boost * 2);
}