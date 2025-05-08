#include "Dragon.h"

Dragon::Dragon() : Monster("Dragon", 200, 30, 15) {}
Dragon::Dragon(int hp, int atk, int def) : Monster("Dragon", hp, atk, def) {}

std::unique_ptr<Monster> Dragon::clone(int boost) const {
    return std::make_unique<Dragon>(200 + boost * 10, attackPower + boost * 3, defense + boost * 2);
}