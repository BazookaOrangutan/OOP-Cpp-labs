#pragma once
#include "Item.h"
#include "Character.h"
#include <vector>

class Inventory {
    std::vector<Item> items;
public:
    void addItem(const Item& item);
    void showInventory() const;
    void applyItemEffects(Character& character);
    void save(std::ofstream& out) const;
    void load(std::ifstream& in);
};
